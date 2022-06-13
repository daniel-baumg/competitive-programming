#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("piggyback.in");
    ofstream fout("piggyback.out");

    int b, e, p, n, m;
    fin >> b >> e >> p >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    int d1[n], d2[n], d3[n];
    queue<int> q;
    bool visited[n] = {};
    visited[0] = true;
    d1[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int v : adj[cur]) {
            if (visited[v])
                continue;
            visited[v] = true;
            d1[v] = d1[cur] + 1;
            q.push(v);
        }
    }
    fill_n(visited, n, false);
    visited[1] = true;
    d2[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int v : adj[cur]) {
            if (visited[v])
                continue;
            visited[v] = true;
            d2[v] = d2[cur] + 1;
            q.push(v);
        }
    }
    fill_n(visited, n, false);
    visited[n - 1] = true;
    d3[n - 1] = 0;
    q.push(n - 1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int v : adj[cur]) {
            if (visited[v])
                continue;
            visited[v] = true;
            d3[v] = d3[cur] + 1;
            q.push(v);
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
        ans = min(ans, b * d1[i] + e * d2[i] + p * d3[i]);
    fout << ans << endl;
}