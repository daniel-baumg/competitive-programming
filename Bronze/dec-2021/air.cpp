#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int p[n], t[n];
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> t[i];

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(p[i] - t[i]);
    for (int i = 0; i < n - 1; i++)
        if ((p[i] - t[i]) * (p[i + 1] - t[i + 1]) > 0)
            ans -= min(abs(p[i] - t[i]), abs(p[i + 1] - t[i + 1]));
    cout << ans << endl;
}