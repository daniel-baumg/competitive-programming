#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000];

int main() {
    ifstream fin("planting.in");
    ofstream fout("planting.out");

    int n;
    fin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        fin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, (int) adj[i].size());
    fout << ans + 1 << endl;
}
