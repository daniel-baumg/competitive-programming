#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];

int main() {
    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");

    int n, m;
    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    int ans[100] = {};
    for (int i = 0; i < n; i++) {
        bool grass[5];
        grass[1] = true;
        grass[2] = true;
        grass[3] = true;
        grass[4] = true;
        for (int v : adj[i])
            grass[ans[v]] = false;
        for (int j = 1; j < 5; j++)
            if (grass[j]) {
                ans[i] = j;
                break;
            }
    }

    for (int i = 0; i < n; i++)
        fout << ans[i];
    fout << endl;
}
