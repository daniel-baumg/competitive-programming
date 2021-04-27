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
        adj[p - 1].push_back(make_pair(q - 1, r));
        adj[q - 1].push_back(make_pair(p - 1, r));
    }

    for (int i = 0; i < q; i++) {
        int k, v;
        fin >> k >> v;
        bool visited[5000] = {};
        int ans = -1;
        queue<int> q;
        q.push(v - 1);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (visited[cur])
                continue;
            visited[cur] = true;
            ans += 1;
            for (pair<int, int> u : adj[cur])
                if (u.second >= k)
                    q.push(u.first);
        }
        fout << ans << endl;
    }
}