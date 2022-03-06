#include <bits/stdc++.h>
using namespace std;

int id[400];

int find(int v) {
    if (v == id[v])
        return v;
    return id[v] = find(id[v]);
}

void merge(int u, int v) {
    int a = find(u);
    int b = find(v);
    id[a] = b;
}

int main() {
    ifstream fin("where.in");
    ofstream fout("where.out");

    int n;
    fin >> n;
    string grid[20];
    for (int i = 0; i < n; i++)
        fin >> grid[i];

    set<pair<pair<int, int>, pair<int, int>>> pcl;
    for (int x1 = 0; x1 < n; x1++) {
        for (int y1 = 0; y1 < n; y1++) {
            for (int x2 = x1; x2 < n; x2++) {
                for (int y2 = y1; y2 < n; y2++) {
                    set<char> s;
                    for (int i = x1; i <= x2; i++)
                        for (int j = y1; j <= y2; j++)
                            s.insert(grid[i][j]);
                    if (s.size() != 2)
                        continue;
                    for (int i = 0; i < n * n; i++)
                        id[i] = i;
                    for (int i = x1; i <= x2; i++) {
                        for (int j = y1; j <= y2; j++) {
                            if (i != x2 && grid[i][j] == grid[i + 1][j]) merge(i + j * n, i + j * n + 1);
                            if (j != y2 && grid[i][j] == grid[i][j + 1]) merge(i + j * n, i + j * n + n);
                        }
                    }
                    int roots[2] = {};
                    vector<char> colors;
                    for (char c : s)
                        colors.push_back(c);
                    for (int i = x1; i <= x2; i++) {
                        for (int j = y1; j <= y2; j++) {
                            if (find(i + j * n) == i + j * n && grid[i][j] == colors[0]) roots[0] += 1;
                            if (find(i + j * n) == i + j * n && grid[i][j] == colors[1]) roots[1] += 1;
                        }
                    }
                    if ((roots[0] == 1 && roots[1] > 1) || (roots[1] == 1 && roots[0] > 1))
                        pcl.insert({{x1, y1}, {x2, y2}});
                }
            }
        }
    }

    int ans = 0;
    for (auto p1 : pcl) {
        bool valid = true;
        for (auto p2 : pcl) {
            if (p1 == p2)
                continue;
            int p1x1 = p1.first.first;
            int p1y1 = p1.first.second;
            int p1x2 = p1.second.first;
            int p1y2 = p1.second.second;
            int p2x1 = p2.first.first;
            int p2y1 = p2.first.second;
            int p2x2 = p2.second.first;
            int p2y2 = p2.second.second;
            if (p2x1 <= p1x1 && p2y1 <= p1y1 && p2x2 >= p1x2 && p2y2 >= p1y2)
                valid = false;
        }
        if (valid)
            ans += 1;
    }
    fout << ans << endl;
}
