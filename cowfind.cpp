#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("cowfind.in");
    ofstream fout("cowfind.out");

    string s;
    fin >> s;
    int ans = 0;
    int k = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '(' && s[i - 1] == '(')
            k += 1;
        if (s[i] == ')' && s[i - 1] == ')')
            ans += k;
    }
    fout << ans << endl;
}