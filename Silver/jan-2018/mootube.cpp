#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[5000];

int main() {
    ifstream fin("mootube.in");
    ofstream fout("mootube.out");

    int n, q;
    fin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int p, q, r;
        fin >> p >> q >> r;
        adj[p - 1].push_back({q - 1, r});
        adj[q - 1].push_back({p - 1, r});
    }

    for (int i = 0; i < q; i++) {
        int k, v;
        fin >> k >> v;
        int ans = -1;
        bool visited[5000] = {};
        visited[v - 1] = true;
        queue<int> q;
        q.push(v - 1);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ans += 1;
            for (auto u : adj[cur]) {
                if (!visited[u.first] && u.second >= k) {
                    q.push(u.first);
                    visited[u.first] = true;
                }
            }
        }
        fout << ans << endl;
    }
}
