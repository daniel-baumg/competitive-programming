#include <bits/stdc++.h>
using namespace std;

int mapping[100000], id[100000];

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

void reverse(int l, int r) {
    int temp[100000];
    for (int i = 0; i < r - l + 1; i++)
        temp[i] = mapping[r - i];
    for (int i = 0; i < r - l + 1; i++)
        mapping[l + i] = temp[i];
}

int main() {
    ifstream fin("swap.in");
    ofstream fout("swap.out");

    int n, m, k;
    fin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        mapping[i] = i;
    for (int i = 0; i < m; i++) {
        int l, r;
        fin >> l >> r;
        reverse(l - 1, r - 1);
    }

    for (int i = 0; i < n; i++)
        id[i] = i;
    for (int i = 0; i < n; i++)
        merge(i, mapping[i]);
    int len[100000] = {};
    for (int i = 0; i < n; i++)
        len[find(i)] += 1;

    int ans[100000];
    fill_n(ans, n, -1);
    for (int i = 0; i < n; i++) {
        if (ans[i] != -1)
            continue;
        int temp = i;
        for (int j = 0; j < k % len[find(i)]; j++)
            temp = mapping[temp];
        int idx = i;
        while (ans[idx] == -1) {
            ans[idx] = temp;
            idx = mapping[idx];
            temp = mapping[temp];
        }
    }
    for (int i = 0; i < n; i++)
        fout << ans[i] + 1 << endl;
}
