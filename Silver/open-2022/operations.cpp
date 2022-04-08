#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int q;
    cin >> s >> q;

    char prefix[200001];
    prefix[0] = ' ';
    for (int i = 0; i < s.size(); i++) {
        if (prefix[i] == ' ' && s[i] == 'C') prefix[i + 1] = 'C';
        if (prefix[i] == ' ' && s[i] == 'O') prefix[i + 1] = 'O';
        if (prefix[i] == ' ' && s[i] == 'W') prefix[i + 1] = 'W';
        if (prefix[i] == 'C' && s[i] == 'C') prefix[i + 1] = ' ';
        if (prefix[i] == 'C' && s[i] == 'O') prefix[i + 1] = 'W';
        if (prefix[i] == 'C' && s[i] == 'W') prefix[i + 1] = 'O';
        if (prefix[i] == 'O' && s[i] == 'C') prefix[i + 1] = 'W';
        if (prefix[i] == 'O' && s[i] == 'O') prefix[i + 1] = ' ';
        if (prefix[i] == 'O' && s[i] == 'W') prefix[i + 1] = 'C';
        if (prefix[i] == 'W' && s[i] == 'C') prefix[i + 1] = 'O';
        if (prefix[i] == 'W' && s[i] == 'O') prefix[i + 1] = 'C';
        if (prefix[i] == 'W' && s[i] == 'W') prefix[i + 1] = ' ';
    }

    string ans = "";
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (prefix[l - 1] == ' ' && prefix[r] == 'C') ans += 'Y';
        if (prefix[l - 1] == ' ' && prefix[r] != 'C') ans += 'N';
        if (prefix[l - 1] == 'C' && prefix[r] == ' ') ans += 'Y';
        if (prefix[l - 1] == 'C' && prefix[r] != ' ') ans += 'N';
        if (prefix[l - 1] == 'O' && prefix[r] == 'W') ans += 'Y';
        if (prefix[l - 1] == 'O' && prefix[r] != 'W') ans += 'N';
        if (prefix[l - 1] == 'W' && prefix[r] == 'O') ans += 'Y';
        if (prefix[l - 1] == 'W' && prefix[r] != 'O') ans += 'N';
    }
    cout << ans << endl;
}