#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");

    int n;
    fin >> n;
    int x[200], y[200], p[200];
    for (int i = 0; i < n; i++)
        fin >> x[i] >> y[i] >> p[i];
    vector<int> adj[200];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            if (sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)) <= p[i])
                adj[i].push_back(j);
        }
    }

    int count[200] = {};
    for (int i = 0; i < n; i++) {
        bool visited[200] = {};
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (visited[cur])
                continue;
            visited[cur] = true;
            count[i] += 1;
            for (int v : adj[cur])
                q.push(v);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, count[i]);
    fout << ans << endl;
}
