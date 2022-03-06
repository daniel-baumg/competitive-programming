#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("art.in");
    ofstream fout("art.out");

    int n;
    fin >> n;
    string grid[10];
    for (int i = 0; i < n; i++)
        fin >> grid[i];

    set<char> s;
    for (int i = 0; i < n; i++)
        for (char c : grid[i])
            if (c != '0')
                s.insert(c);

    int ans = 0;
    for (auto c : s) {
        bool valid = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != c)
                    continue;
                for (int x1 = 0; x1 < n; x1++) {
                    for (int y1 = 0; y1 < n; y1++) {
                        for (int x2 = 0; x2 < n; x2++) {
                            for (int y2 = 0; y2 < n; y2++) {
                                if (x1 == i && y1 == j) continue;
                                if (x2 == i && y2 == j) continue;
                                if (grid[x1][y1] != grid[x2][y2] || grid[x1][y1] == '0' || grid[x1][y1] == c)
                                    continue;
                                if (x1 <= i && i <= x2 && y1 <= j && j <= y2) valid = false;
                                if (x2 <= i && i <= x1 && y1 <= j && j <= y2) valid = false;
                            }
                        }
                    }
                }
            }
        }
        if (valid)
            ans += 1;
    }
    fout << ans << endl;
}