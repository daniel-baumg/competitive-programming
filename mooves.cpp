#include <bits/stdc++.h>
using namespace std;

int cows[200000], id[200000];
set<int> s[200000], ans[200000];

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

void swap(int x, int y) {
    int temp = cows[x];
    cows[x] = cows[y];
    cows[y] = temp;
    s[cows[x]].insert(y);
    s[cows[y]].insert(x);
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cows[i] = i;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        swap(a - 1, b - 1);
    }

    for (int i = 0; i < n; i++)
        id[i] = i;
    for (int i = 0; i < n; i++)
        merge(i, cows[i]);

    for (int i = 0; i < n; i++) {
        s[i].insert(i);
        for (int v : s[i])
            ans[find(i)].insert(v);
    }
    for (int i = 0; i < n; i++)
        cout << ans[find(i)].size() << endl;
}