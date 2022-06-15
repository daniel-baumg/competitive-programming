#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] -= 1;
    }

    int ans = 0;
    int cur = 0;
    bool done[n] = {};
    for (int i = 0; i < n; i++) {
        if (a[cur] != b[i])
            ans += 1;
        done[b[i]] = true;
        while (cur < n && done[a[cur]])
            cur += 1;
    }
    cout << ans << endl;
}