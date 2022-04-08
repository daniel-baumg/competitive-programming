#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    int q;
    cin >> s >> t >> q;

    map<pair<char, char>, bool> m;
    string a = "abcdefghijklmnopqr";
    for (int i = 0; i < 20; i++) {
        for (int j = i; j < 20; j++) {
            string ss = "";
            string tt = "";
            for (char c : s) if (c == a[i] || c == a[j]) ss += c;
            for (char c : t) if (c == a[i] || c == a[j]) tt += c;
            m[{a[i], a[j]}] = ss == tt;
            m[{a[j], a[i]}] = ss == tt;
        }
    }

    string ans = "";
    while (q--) {
        string k;
        cin >> k;
        bool valid = true;
        for (int i = 0; i < k.size(); i++)
            for (int j = i; j < k.size(); j++)
                valid &= m[{k[i], k[j]}];
        if (valid)
            ans += 'Y';
        else
            ans += 'N';
    }
    cout << ans << endl;
}
