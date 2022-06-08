#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long ans = 0;
        for (int i = 1; i < n - 1; i++) {
            int k = max(0, a[i] - a[i - 1]);
            k = min(k, a[i]);
            k = min(k, a[i + 1]);
            ans += k;
            a[i] -= k;
            a[i + 1] -= k;
        }
        for (int i = n - 2; i > 0; i--) {
            int k = max(0, a[i] - a[i + 1]);
            k = min(k, a[i - 1]);
            k = min(k, a[i]);
            ans += k;
            a[i] -= k;
            a[i - 1] -= k;
        }
        ans *= 2;
        bool valid = true;
        for (int i = 0; i < n; i++)
            valid &= a[i] == a[0];
        if (!valid)
            ans = -1;
        cout << ans << endl;
    }
}