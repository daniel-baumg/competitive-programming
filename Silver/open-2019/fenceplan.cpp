#include <bits/stdc++.h>
using namespace std;

int id[100000], minx[100000], miny[100000], maxx[100000], maxy[100000];

int find(int v) {
    if (v == id[v])
        return v;
    return id[v] = find(id[v]);
}

void merge(int u, int v) {
    int a = find(u);
    int b = find(v);
    id[a] = b;
}

int main() {
    ifstream fin("fenceplan.in");
    ofstream fout("fenceplan.out");

    int n, m;
    fin >> n >> m;
    int x[100000], y[100000];
    for (int i = 0; i < n; i++) {
        fin >> x[i] >> y[i];
        id[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;
        merge(a - 1, b - 1);
    }

    fill_n(minx, n, INT_MAX);
    fill_n(miny, n, INT_MAX);
    for (int i = 0; i < n; i++) {
        int root = find(i);
        minx[root] = min(minx[root], x[i]);
        miny[root] = min(miny[root], y[i]);
        maxx[root] = max(maxx[root], x[i]);
        maxy[root] = max(maxy[root], y[i]);
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
        if (id[i] == i)
            ans = min(ans, 2 * (maxx[i] - minx[i]) + 2 * (maxy[i] - miny[i]));
    fout << ans << endl;
}
