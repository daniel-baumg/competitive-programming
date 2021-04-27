#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("lostcow.in");
    ofstream fout("lostcow.out");

    int x, y;
    fin >> x >> y;
    int ans = 0;
    int d = 1;
    while ((x < y && d < 0) || (x < y && d > 0 && x + d < y) || (x > y && d > 0) || (x > y && d < 0 && x + d > y)) {
        ans += 2 * abs(d);
        d *= -2;
    }
    ans += abs(d) - abs(x + d - y);
    fout << ans << endl;
}