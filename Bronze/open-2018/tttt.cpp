#include <bits/stdc++.h>
using namespace std;

string board[3];

int num_distinct(string s) {
    if (s[0] == s[1] && s[1] == s[2])
        return 1;
    if (s[0] == s[1] || s[1] == s[2] || s[0] == s[2])
        return 2;
    return 3;
}

bool wins(char c) {
    if (c == board[0][0] && c == board[0][1] && c == board[0][2]) return true;
    if (c == board[1][0] && c == board[1][1] && c == board[1][2]) return true;
    if (c == board[2][0] && c == board[2][1] && c == board[2][2]) return true;
    if (c == board[0][0] && c == board[1][0] && c == board[2][0]) return true;
    if (c == board[0][1] && c == board[1][1] && c == board[2][1]) return true;
    if (c == board[0][2] && c == board[1][2] && c == board[2][2]) return true;
    if (c == board[0][0] && c == board[1][1] && c == board[2][2]) return true;
    if (c == board[0][2] && c == board[1][1] && c == board[2][0]) return true;
    return false;
}

bool wins(char c1, char c2) {
    char c = '.';
    string board_replaced[3] = {board[0], board[1], board[2]};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == c1 || board[i][j] == c2)
                board_replaced[i][j] = c;
    string s1 = string(1, board[0][0]) + board[0][1] + board[0][2];
    string s2 = string(1, board[1][0]) + board[1][1] + board[1][2];
    string s3 = string(1, board[2][0]) + board[2][1] + board[2][2];
    string s4 = string(1, board[0][0]) + board[1][0] + board[2][0];
    string s5 = string(1, board[0][1]) + board[1][1] + board[2][1];
    string s6 = string(1, board[0][2]) + board[1][2] + board[2][2];
    string s7 = string(1, board[0][0]) + board[1][1] + board[2][2];
    string s8 = string(1, board[0][2]) + board[1][1] + board[2][0];
    if (c == board_replaced[0][0] && c == board_replaced[0][1] && c == board_replaced[0][2] && num_distinct(s1) == 2) return true;
    if (c == board_replaced[1][0] && c == board_replaced[1][1] && c == board_replaced[1][2] && num_distinct(s2) == 2) return true;
    if (c == board_replaced[2][0] && c == board_replaced[2][1] && c == board_replaced[2][2] && num_distinct(s3) == 2) return true;
    if (c == board_replaced[0][0] && c == board_replaced[1][0] && c == board_replaced[2][0] && num_distinct(s4) == 2) return true;
    if (c == board_replaced[0][1] && c == board_replaced[1][1] && c == board_replaced[2][1] && num_distinct(s5) == 2) return true;
    if (c == board_replaced[0][2] && c == board_replaced[1][2] && c == board_replaced[2][2] && num_distinct(s6) == 2) return true;
    if (c == board_replaced[0][0] && c == board_replaced[1][1] && c == board_replaced[2][2] && num_distinct(s7) == 2) return true;
    if (c == board_replaced[0][2] && c == board_replaced[1][1] && c == board_replaced[2][0] && num_distinct(s8) == 2) return true;
    return false;
}

int main() {
    ifstream fin("tttt.in");
    ofstream fout("tttt.out");

    fin >> board[0] >> board[1] >> board[2];
    string cows = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int ans = 0;
    for (int i = 0; i < 26; i++)
        if (wins(cows[i]))
            ans += 1;
    fout << ans << endl;

    ans = 0;
    for (int i = 0; i < 26; i++)
        for (int j = i + 1; j < 26; j++)
            if (wins(cows[i], cows[j]))
                ans += 1;
    fout << ans << endl;
}
