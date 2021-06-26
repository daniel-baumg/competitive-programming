#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    int c[100000];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    sort(c, c + n);

    int h = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] >= n - i) {
            h = n - i;
            break;
        }
    }

    int ans = h;
    if (h < n && c[n - h - 1] == h) {
        int num = 0;
        for (int i = 0; i < h + 1; i++)
            if (c[n - i - 1] == h)
                num += 1;
        if (num <= l)
            ans += 1;
    }
    cout << ans << endl;
}
