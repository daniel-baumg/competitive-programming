#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int o = 0;
    int e = 0;
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        if (id % 2 == 0)
            e += 1;
        else
            o += 1;
    }

    int ans = 0;
    while (true) {
        if (ans % 2 == 0 && e == 0 && o < 2)
            break;
        if (ans % 2 == 1 && o == 0)
            break;
        if (ans % 2 == 1)
            o -= 1;
        else if (ans % 2 == 0 && e > 0)
            e -= 1;
        else if (ans % 2 == 0 && e == 0)
            o -= 2;
        ans += 1;
    }
    if (o == 1)
        ans -= 1;
    cout << ans << endl;
}
