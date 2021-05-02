#include <bits/stdc++.h>
using namespace std;

bool occupied[1003][1003];

int count(int x, int y) {
    int num = 0;
    if (occupied[x - 1][y]) num += 1;
    if (occupied[x + 1][y]) num += 1;
    if (occupied[x][y - 1]) num += 1;
    if (occupied[x][y + 1]) num += 1;
    return num;
}

int main() {
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x += 1;
        y += 1;
        occupied[x][y] = true;
        if (count(x, y) == 3) ans += 1;
        if (occupied[x + 1][y] && count(x + 1, y) == 3) ans += 1;
        if (occupied[x - 1][y] && count(x - 1, y) == 3) ans += 1;
        if (occupied[x][y + 1] && count(x, y + 1) == 3) ans += 1;
        if (occupied[x][y - 1] && count(x, y - 1) == 3) ans += 1;
        if (occupied[x + 1][y] && count(x + 1, y) == 4) ans -= 1;
        if (occupied[x - 1][y] && count(x - 1, y) == 4) ans -= 1;
        if (occupied[x][y + 1] && count(x, y + 1) == 4) ans -= 1;
        if (occupied[x][y - 1] && count(x, y - 1) == 4) ans -= 1;
        cout << ans << endl;
    }
}