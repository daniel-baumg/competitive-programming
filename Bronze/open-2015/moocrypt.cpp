#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("moocrypt.in");
    ofstream fout("moocrypt.out");

    int n, m;
    fin >> n >> m;
    string grid[n][m];
    for (int i = 0; i < n; i++) {
        string s;
        fin >> s;
        for (int j = 0; j < m; j++)
            grid[i][j] = s[j];
    }

    map<string, int> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (0 < i && i < n - 1) {
                k[grid[i - 1][j] + grid[i][j] + grid[i + 1][j]] += 1;
                k[grid[i + 1][j] + grid[i][j] + grid[i - 1][j]] += 1;
            }
            if (0 < j && j < m - 1) {
                k[grid[i][j - 1] + grid[i][j] + grid[i][j + 1]] += 1;
                k[grid[i][j + 1] + grid[i][j] + grid[i][j - 1]] += 1;
            }
            if (0 < i && i < n - 1 && 0 < j && j < m - 1) {
                k[grid[i - 1][j - 1] + grid[i][j] + grid[i + 1][j + 1]] += 1;
                k[grid[i + 1][j + 1] + grid[i][j] + grid[i - 1][j - 1]] += 1;
                k[grid[i - 1][j + 1] + grid[i][j] + grid[i + 1][j - 1]] += 1;
                k[grid[i + 1][j - 1] + grid[i][j] + grid[i - 1][j + 1]] += 1;
            }
        }
    }

    int ans = 0;
    for (auto p : k)
        if (p.first[0] != 'M' && p.first[0] != p.first[1] && p.first[1] != 'O' && p.first[1] == p.first[2])
            ans = max(ans, p.second);
    fout << ans << endl;
}