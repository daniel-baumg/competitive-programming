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

        long long sum = 0;
        for (int i : a)
            sum += i;
        set<long long> s;
        for (int i = 1; i <= sqrt(sum); i++) {
            if (sum % i == 0) {
                s.insert(i);
                s.insert(sum / i);
            }
        }
        if (sum == 0) {
            cout << 0 << endl;
            continue;
        }

        int ans = n - 1;
        for (auto i : s) {
            bool valid = true;
            long long cur = 0;
            int k = 0;
            for (int j = 0; j < n; j++) {
                cur += a[j];
                k += 1;
                valid &= cur <= i;
                if (cur >= i) {
                    cur = 0;
                    k -= 1;
                }
            }
            if (valid)
                ans = min(ans, k);
        }
        cout << ans << endl;
    }
}