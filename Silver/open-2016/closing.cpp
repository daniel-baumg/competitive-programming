#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("closing.in");
    ofstream fout("closing.out");

    int n, m;
    fin >> n >> m;
    vector<int> adj[3000];
    for (int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    int barns[3000];
    for (int i = 0; i < n; i++)
        fin >> barns[i];

    bool open[3000];
    fill_n(open, n, true);
    for (int i = 0; i < n; i++) {
        int reachable = 0;
        bool visited[3000] = {};
        visited[barns[n - 1] - 1] = true;
        queue<int> q;
        q.push(barns[n - 1] - 1);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            reachable += 1;
            for (int v : adj[cur]) {
                if (!visited[v] && open[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        if (reachable == n - i)
            fout << "YES" << endl;
        else
            fout << "NO" << endl;
        open[barns[i] - 1] = false;
    }
}
