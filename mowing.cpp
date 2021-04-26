#include <bits/stdc++.h>
using namespace std;

vector<int> grid[2001][2001];

int main() {
    ifstream fin("mowing.in");
    ofstream fout("mowing.out");

    int n;
    fin >> n;
    grid[1000][1000].push_back(0);
    int x = 1000;
    int y = 1000;
    int time = 0;
    for (int i = 0; i < n; i++) {
        string d;
        int s;
        fin >> d >> s;
        for (int j = 0; j < s; j++) {
            if (d == "N")
                y += 1;
            if (d == "S")
                y -= 1;
            if (d == "E")
                x += 1;
            if (d == "W")
                x -= 1;
            time += 1;
            grid[x][y].push_back(time);
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < 2001; i++)
        for (int j = 0; j < 2001; j++)
            for (int k = 1; k < grid[i][j].size(); k++)
                ans = min(ans, grid[i][j][k] - grid[i][j][k - 1]);
    if (ans == INT_MAX)
        ans = -1;
    fout << ans << endl;
}