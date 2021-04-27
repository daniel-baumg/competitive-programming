#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("circlecross.in");
    ofstream fout("circlecross.out");

    string s;
    fin >> s;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            vector<int> a, b;
            for (int k = 0; k < 52; k++) {
                if (s[k] == alphabet[i])
                    a.push_back(k);
                if (s[k] == alphabet[j])
                    b.push_back(k);
            }
            if (a[0] < b[0] && b[0] < a[1] && a[1] < b[1])
                ans += 1;
            if (b[0] < a[0] && a[0] < b[1] && b[1] < a[1])
                ans += 1;
        }
    }
    fout << ans << endl;
}
