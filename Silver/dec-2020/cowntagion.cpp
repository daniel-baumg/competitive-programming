#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    adj[0].push_back(0);

    int ans = 0;
    bool visited[100000] = {};
    stack<int> s;
    s.push(0);
    visited[0] = true;
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        ans += ceil(log(adj[cur].size()) / log(2));
        for (int v : adj[cur]) {
            if (!visited[v]) {
                ans += 1;
                s.push(v);
                visited[v] = true;
            }
        }
    }
    cout << ans << endl;
}
