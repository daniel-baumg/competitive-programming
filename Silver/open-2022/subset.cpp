#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    int q;
    cin >> s >> t >> q;

    map<pair<char, char>, bool> m;
    string alphabet = "abcdefghijklmnopqr";
    for (char c1 : alphabet) {
        for (char c2 : alphabet) {
            string ss = "";
            string tt = "";
            for (char c : s) if (c == c1 || c == c2) ss += c;
            for (char c : t) if (c == c1 || c == c2) tt += c;
            m[{c1, c2}] = ss == tt;
        }
    }

    string ans = "";
    while (q--) {
        string k;
        cin >> k;
        bool valid = true;
        for (char c1 : k)
            for (char c2 : k)
                valid &= m[{c1, c2}];
        if (valid)
            ans += 'Y';
        else
            ans += 'N';
    }
    cout << ans << endl;
}
