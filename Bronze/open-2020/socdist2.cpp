#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("socdist2.in");
    ofstream fout("socdist2.out");

    int n;
    fin >> n;
    pair<int, int> cows[1000];
    for (int i = 0; i < n; i++) {
        int x, s;
        fin >> x >> s;
        cows[i] = {x, s};
    }
    sort(cows, cows + n);

    int r = INT_MAX;
    for (int i = 0; i < n - 1; i++)
        if (cows[i].second + cows[i + 1].second == 1)
            r = min(r, cows[i + 1].first - cows[i].first - 1);

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (cows[i].second == 0 && cows[i + 1].second == 0)
            continue;
        if (cows[i].second == 0 && cows[i + 1].second == 1)
            ans += 1;
        if (cows[i].second + cows[i + 1].second == 2 && cows[i + 1].first - cows[i].first > r)
            ans += 1;
    }
    if (cows[0].second == 1)
        ans += 1;
    fout << ans << endl;
}
