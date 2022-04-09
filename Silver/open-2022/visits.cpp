#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[100000], v[100000];
    for (int i = 0; i < n; i++)
        cin >> a[i] >> v[i];

    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += v[i];
    bool done[n] = {};
    for (int i = 0; i < n; i++) {
        int u = i;
        int mn = INT_MAX;
        set<int> visited, cycle;
        while (visited.count(u) == 0) {
            if (done[u])
                goto next;
            done[u] = true;
            visited.insert(u);
            u = a[u] - 1;
        }
        while (cycle.count(u) == 0) {
            cycle.insert(u);
            mn = min(mn, v[u]);
            u = a[u] - 1;
        }
        ans -= mn;
        next: continue;
    }
    cout << ans;
}