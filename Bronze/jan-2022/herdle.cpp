#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1[3], s2[3];
    cin >> s1[0] >> s1[1] >> s1[2] >> s2[0] >> s2[1] >> s2[2];

    int ans1 = 0;
    int ans2 = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (s1[i][j] == s2[i][j])
                ans1 += 1;
    for (char c : "ABCDEFGHIJKLMNOPQRSTUVWXYZ") {
        int n1 = 0;
        int n2 = 0;
        for (string s : s1) {
            if (s[0] == c) n1 += 1;
            if (s[1] == c) n1 += 1;
            if (s[2] == c) n1 += 1;
        }
        for (string s : s2) {
            if (s[0] == c) n2 += 1;
            if (s[1] == c) n2 += 1;
            if (s[2] == c) n2 += 1;
        }
        int k = min(n1, n2);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (s1[i][j] == c && s2[i][j] == c)
                    k -= 1;
        ans2 += k;
    }
    cout << ans1 << endl << ans2 << endl;
}
