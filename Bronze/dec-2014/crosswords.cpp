#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("crosswords.in");
    ofstream fout("crosswords.out");

    int n, m;
    fin >> n >> m;
    string grid[50];
    for (int i = 0; i < n; i++)
        fin >> grid[i];
 
    int ans = 0;
    vector<int> x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool h = false;
            bool v = false;
            if (j < m - 2) h = (j == 0 || grid[i][j - 1] == '#') && (grid[i][j] == '.' && grid[i][j + 1] == '.' && grid[i][j + 2] == '.');
            if (i < n - 2) v = (i == 0 || grid[i - 1][j] == '#') && (grid[i][j] == '.' && grid[i + 1][j] == '.' && grid[i + 2][j] == '.');
            if (h || v) {
                ans += 1;
                x.push_back(i + 1);
                y.push_back(j + 1);
            }
        }
    }
    fout << ans << endl;
    for (int i = 0; i < ans; i++)
        fout << x[i] << " " << y[i] << endl;
}
