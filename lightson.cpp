#include <bits/stdc++.h>
using namespace std;

bool lit[100][100] = {};
bool toggled[100][100] = {};
multimap<pair<int, int>, pair<int, int>> mm;

bool illuminate(int n) {
    bool result = false;
    bool visited[100][100] = {};
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if (cur.first < 0 || cur.first >= n || cur.second < 0 || cur.second >= n)
            continue;
        if (visited[cur.first][cur.second] || !lit[cur.first][cur.second])
            continue;
        visited[cur.first][cur.second] = true;
        if (!toggled[cur.first][cur.second]) {
            auto it = mm.equal_range(cur);
            for (auto itr = it.first; itr != it.second; itr++)
                lit[itr -> second.first][itr -> second.second] = true;
            toggled[cur.first][cur.second] = true;
            result = true;
        }
        q.push(make_pair(cur.first + 1, cur.second));
        q.push(make_pair(cur.first - 1, cur.second));
        q.push(make_pair(cur.first, cur.second + 1));
        q.push(make_pair(cur.first, cur.second - 1));
    }
    return result;
}

int main() {
    ifstream fin("lightson.in");
    ofstream fout("lightson.out");

    int n, m;
    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, a, b;
        fin >> x >> y >> a >> b;
        mm.insert(make_pair(make_pair(x - 1, y - 1), make_pair(a - 1, b - 1)));
    }

    lit[0][0] = true;
    while (illuminate(n))
        continue;

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (lit[i][j])
                ans += 1;
    fout << ans << endl;
}