#include <bits/stdc++.h>
using namespace std;

int n;
int c[100000];

bool valid(int h) {
    int num = 0;
    for (int i = 0; i < n; i++)
        if (c[i] >= h)
            num += 1;
    return num >= h;
}

int main() {
    int l;
    cin >> n >> l;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    sort(c, c + n);

    int h;
    int lo = 0;
    int hi = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (valid(mid)) {
            h = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
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
