#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<long long> g, h;
    g.push_back(-1);
    h.push_back(-1);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'G') g.push_back(i);
        if (s[i] == 'H') h.push_back(i);
    }
    g.push_back(n);
    h.push_back(n);

    long long ans = 0;
    for (int i = 1; i < g.size() - 1; i++) {
        long long k = (g[i] - g[i - 1]) * (g[i + 1] - g[i]) - 1;
        if (g[i] - g[i - 1] > 1) k -= 1;
        if (g[i + 1] - g[i] > 1) k -= 1;
        ans += k;
    }
    for (int i = 1; i < h.size() - 1; i++) {
        long long k = (h[i] - h[i - 1]) * (h[i + 1] - h[i]) - 1;
        if (h[i] - h[i - 1] > 1) k -= 1;
        if (h[i + 1] - h[i] > 1) k -= 1;
        ans += k;
    }
    cout << ans << endl;
}