#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("factory.in");
    ofstream fout("factory.out");

    int n;
    fin >> n;
    vector<int> adj[100];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        fin >> a >> b;
        adj[a - 1].push_back(b - 1);
    }

    int reachable[100] = {};
    for (int i = 0; i < n; i++) {
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            reachable[cur] += 1;
            for (int v : adj[cur])
                q.push(v);
        }
    }

    int ans = -2;
    for (int i = 0; i < n; i++) {
        if (reachable[i] == n) {
            ans = i;
            break;
        }
    }
    fout << ans + 1 << endl;
}
