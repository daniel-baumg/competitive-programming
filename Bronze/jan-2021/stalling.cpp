#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[20], b[20];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);

    long long ans = 1;
    for (int i = 0; i < n; i++) {
        int valid = 0;
        for (int j = 0; j < n; j++)
            if (a[n - i - 1] <= b[j])
                valid += 1;
        ans *= max(0, valid - i);
    }
    cout << ans << endl;
}
