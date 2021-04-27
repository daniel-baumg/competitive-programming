#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("perimeter.in");
    ofstream fout("perimeter.out");

    int n;
    fin >> n;
    string grid[1000];
    for (int i = 0; i < n; i++)
        fin >> grid[i];

    int ans_a = 0;
    int ans_p = 0;
    bool visited[1000][1000] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j])
                continue;
            int a = 0;
            int p = 0;
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                if (cur.first < 0 || cur.first >= n || cur.second < 0 || cur.second >= n || grid[cur.first][cur.second] == '.') {
                    p += 1;
                    continue;
                }
                if (visited[cur.first][cur.second])
                    continue;
                visited[cur.first][cur.second] = true;
                a += 1;
                q.push(make_pair(cur.first + 1, cur.second));
                q.push(make_pair(cur.first - 1, cur.second));
                q.push(make_pair(cur.first, cur.second + 1));
                q.push(make_pair(cur.first, cur.second - 1));
            }
            if (a == ans_a)
                ans_p = min(ans_p, p);
            if (a > ans_a) {
                ans_a = a;
                ans_p = p;
            }
        }
    }
    fout << ans_a << " " << ans_p << endl;
}
