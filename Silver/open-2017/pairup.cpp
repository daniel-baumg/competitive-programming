#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("pairup.in");
    ofstream fout("pairup.out");

    int n;
    fin >> n;
    pair<int, int> cows[100000];
    for (int i = 0; i < n; i++) {
        int x, y;
        fin >> x >> y;
        cows[i] = {y, x};
    }
    sort(cows, cows + n);

    int ans = 0;
    int lo = 0;
    int hi = n - 1;
    while (lo < hi) {
        ans = max(ans, cows[lo].first + cows[hi].first);
        int change = min(cows[lo].second, cows[hi].second);
        cows[lo].second -= change;
        cows[hi].second -= change;
        if (cows[lo].second == 0) lo += 1;
        if (cows[hi].second == 0) hi -= 1;
    }
    if (lo == hi)
        ans = max(ans, cows[lo].first + cows[hi].first);
    fout << ans << endl;
}
