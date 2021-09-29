#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("countcross.in");
    ofstream fout("countcross.out");

    int n, k, r;
    fin >> n >> k >> r;
    int farm[201][201] = {};
    for (int i = 0; i < r; i++) {
        int a, b, c, d;
        fin >> a >> b >> c >> d;
        farm[a + c - 1][b + d - 1] = -1;
    }
    pair<int, int> cows[100];
    for (int i = 0; i < k; i++) {
        int x, y;
        fin >> x >> y;
        cows[i] = make_pair(2 * x - 1, 2 * y - 1);
    }
    for (int i = 0; i < 2 * n + 1; i++) farm[i][0] = -1;
    for (int i = 0; i < 2 * n + 1; i++) farm[0][i] = -1;
    for (int i = 0; i < 2 * n + 1; i++) farm[i][2 * n] = -1;
    for (int i = 0; i < 2 * n + 1; i++) farm[2 * n][i] = -1;
    for (int i = 2; i < 2 * n - 1; i += 2)
        for (int j = 2; j < 2 * n - 1; j += 2)
            farm[i][j] = -1;

    for (int i = 0; i < k; i++) {
        queue<pair<int, int>> q;
        q.push(cows[i]);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur.first < 0 || cur.second < 0 || cur.first > 2 * n || cur.second > 2 * n)
                continue;
            if (farm[cur.first][cur.second] != 0)
                continue;
            farm[cur.first][cur.second] = i + 1;
            q.push(make_pair(cur.first + 1, cur.second));
            q.push(make_pair(cur.first - 1, cur.second));
            q.push(make_pair(cur.first, cur.second + 1));
            q.push(make_pair(cur.first, cur.second - 1));
        }
    }

    int ans = 0;
    for (int i = 0; i < k; i++)
        for (int j = i + 1; j < k; j++)
            if (farm[cows[i].first][cows[i].second] != farm[cows[j].first][cows[j].second])
                ans += 1;
    fout << ans << endl;
}
