#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s[4];
    cin >> n >> s[0] >> s[1] >> s[2] >> s[3];

    set<string> possible;
    for (char c1 : s[0]) {
        for (char c2 : s[1]) {
            for (char c3 : s[2]) {
                for (char c4 : s[3]) {
                    string word = "";
                    word += c1;
                    word += c2;
                    word += c3;
                    word += c4;
                    sort(word.begin(), word.end());
                    do {
                        possible.insert(word.substr(0));
                        possible.insert(word.substr(1));
                        possible.insert(word.substr(2));
                        possible.insert(word.substr(3));
                    } while (next_permutation(word.begin(), word.end()));
                }
            }
        }
    }

    while (n--) {
        string k;
        cin >> k;
        if (possible.count(k) == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
