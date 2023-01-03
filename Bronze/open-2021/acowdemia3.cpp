#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'G' && 0 < i && i < n - 1 && s[i - 1][j] == 'C' && s[i + 1][j] == 'C') {
                ans += 1;
                s[i][j] = '.';
            }
            if (s[i][j] == 'G' && 0 < j && j < m - 1 && s[i][j - 1] == 'C' && s[i][j + 1] == 'C') {
                ans += 1;
                s[i][j] = '.';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'G' && i > 0 && j > 0 && s[i - 1][j] == 'C' && s[i][j - 1] == 'C') {
                ans += 1;
                s[i][j] = '.';
                if (s[i - 1][j - 1] == 'G')
                    s[i - 1][j - 1] = '.';
            }
            if (s[i][j] == 'G' && i < n - 1 && j > 0 && s[i + 1][j] == 'C' && s[i][j - 1] == 'C') {
                ans += 1;
                s[i][j] = '.';
                if (s[i + 1][j - 1] == 'G')
                    s[i + 1][j - 1] = '.';
            }
            if (s[i][j] == 'G' && i > 0 && j < m - 1 && s[i - 1][j] == 'C' && s[i][j + 1] == 'C') {
                ans += 1;
                s[i][j] = '.';
                if (s[i - 1][j + 1] == 'G')
                    s[i - 1][j + 1] = '.';
            }
            if (s[i][j] == 'G' && i < n - 1 && j < m - 1 && s[i + 1][j] == 'C' && s[i][j + 1] == 'C') {
                ans += 1;
                s[i][j] = '.';
                if (s[i + 1][j + 1] == 'G')
                    s[i + 1][j + 1] = '.';
            }
        }
    }
    cout << ans << endl;
}