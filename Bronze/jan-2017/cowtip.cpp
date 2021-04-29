#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("cowtip.in");
    ofstream fout("cowtip.out");

    int n;
    fin >> n;
    string grid[10];
    for (int i = 0; i < n; i++)
        fin >> grid[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[n - i - 1][n - j - 1] == '0')
                continue;
            ans += 1;
            for (int x = 0; x < n - i; x++) {
                for (int y = 0; y < n - j; y++) {
                    if (grid[x][y] == '1')
                        grid[x][y] = '0';
                    else
                        grid[x][y] = '1';
                }
            }
        }
    }
    fout << ans << endl;
}
