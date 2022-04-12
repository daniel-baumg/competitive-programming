#include <bits/stdc++.h>
using namespace std;

int num[2500];
bool visited[2500];
vector<int> adj[2500];

void dfs(int v, int prev) {
    num[v] += 1;
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u, v);
            num[v] += 1;
        }
    }
    while (num[v] % 12 != 0) {
        num[v] += 1;
        num[prev] += 1;
    }
}

int main() {
    ifstream fin("clocktree.in");
    ofstream fout("clocktree.out");

    int n;
    fin >> n;
    int clock[2500];
    for (int i = 0; i < n; i++)
        fin >> clock[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        fin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            num[j] = clock[j];
            visited[j] = false;
        }
        visited[i] = true;
        for (int v : adj[i]) {
            dfs(v, i);
            num[i] += 1;
        }
        if (num[i] % 12 == 0 || num[i] % 12 == 1)
            ans += 1;
    }
    fout << ans << endl;
}