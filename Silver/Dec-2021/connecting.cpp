#include <bits/stdc++.h>
using namespace std;

int id[100010], sz[100010];

int find(int v) {
    if (v == id[v])
        return v;
    return id[v] = find(id[v]);
}

void merge(int u, int v) {
    int a = find(u);
    int b = find(v);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        id[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            id[i] = i;
            sz[i] = 1;
        }
        vector<int> adj[n];
        while (m--) {
            int i, j;
            cin >> i >> j;
            adj[i - 1].push_back(j - 1);
            adj[j - 1].push_back(i - 1);
            merge(i - 1, j - 1);
        }

        long long d1[n] = {};
        long long d2[n] = {};
        queue<int> q;
        bool visited[n] = {};
        for (int i = 0; i < n; i++) {
            if (find(i) == find(0)) {
                visited[i] = true;
                q.push(i);
            }
        }
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur - 1 >= 0 && !visited[cur - 1]) {
                d1[cur - 1] = d1[cur] + 1;
                visited[cur - 1] = true;
                q.push(cur - 1);
            }
            if (cur + 1 < n && !visited[cur + 1]) {
                d1[cur + 1] = d1[cur] + 1;
                visited[cur + 1] = true;
                q.push(cur + 1);
            }
        }
        fill_n(visited, n, false);
        for (int i = 0; i < n; i++) {
            if (find(i) == find(n - 1)) {
                q.push(i);
                visited[i] = true;
            }
        }
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur - 1 >= 0 && !visited[cur - 1]) {
                d2[cur - 1] = d2[cur] + 1;
                visited[cur - 1] = true;
                q.push(cur - 1);
            }
            if (cur + 1 < n && !visited[cur + 1]) {
                d2[cur + 1] = d2[cur] + 1;
                visited[cur + 1] = true;
                q.push(cur + 1);
            }
        }
        for (int i = 0; i < n; i++) {
            d1[find(i)] = min(d1[find(i)], d1[i]);
            d2[find(i)] = min(d2[find(i)], d2[i]);
        }

        long long ans = n * n;
        for (int i = 0; i < n; i++)
            ans = min(ans, d1[find(i)] * d1[find(i)] + d2[find(i)] * d2[find(i)]);
        cout << ans << endl;
    }
}
