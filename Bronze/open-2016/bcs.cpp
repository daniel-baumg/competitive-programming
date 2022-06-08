#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("bcs.in");
    ofstream fout("bcs.out");

    int n, k;
    fin >> n >> k;
    vector<int> original[n];
    for (int i = 0; i < n; i++) {
        string s;
        fin >> s;
        for (char c : s) {
            if (c == '#') original[i].push_back(1);
            if (c == '.') original[i].push_back(0);
        }
    }
    string p[k][n];
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            fin >> p[i][j];

    int ans1, ans2;
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            for (int x1 = -n + 1; x1 < n; x1++) {
                for (int y1 = -n + 1; y1 < n; y1++) {
                    for (int x2 = -n + 1; x2 < n; x2++) {
                        for (int y2 = -n + 1; y2 < n; y2++) {
                            bool valid = true;
                            int combined[n][n] = {};
                            for (int x = 0; x < n; x++) {
                                for (int y = 0; y < n; y++) {
                                    if (x + x1 < 0 || y + y1 < 0 || x + x1 >= n || y + y1 >= n) {
                                        valid &= p[i][x][y] == '.';
                                    } else if (p[i][x][y] == '#') {
                                        combined[x1 + x][y1 + y] += 1;
                                    }
                                    if (x + x2 < 0 || y + y2 < 0 || x + x2 >= n || y + y2 >= n) {
                                        valid &= p[j][x][y] == '.';
                                    } else if (p[j][x][y] == '#') {
                                        combined[x2 + x][y2 + y] += 1;
                                    }
                                    if (!valid) goto next;
                                }
                            }
                            for (int x = 0; x < n; x++)
                                for (int y = 0; y < n; y++)
                                    valid &= combined[x][y] == original[x][y];
                            if (valid) {
                                ans1 = i + 1;
                                ans2 = j + 1;
                            }
                            next: continue;
                        }
                    }
                }
            }
        }
    }
    fout << ans1 << " " << ans2 << endl;
}