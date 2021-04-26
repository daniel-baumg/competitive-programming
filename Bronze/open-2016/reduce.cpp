#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("reduce.in");
    ofstream fout("reduce.out");

    int n;
    fin >> n;
    int x[50000], y[50000], area[50000];
    for (int i = 0; i < n; i++)
        fin >> x[i] >> y[i];
    int minx = INT_MAX;
    int miny = INT_MAX;
    int maxx = 0;
    int maxy = 0;
    for (int i = 0; i < n; i++) {
        minx = min(minx, x[i]);
        miny = min(miny, y[i]);
        maxx = max(maxx, x[i]);
        maxy = max(maxy, y[i]);
    }

    fill_n(area, n, INT_MAX);
    for (int i = 0; i < n; i++) {
        if (x[i] != minx && x[i] != maxx && y[i] != miny && y[i] != maxy)
            continue;
        int x1 = INT_MAX;
        int y1 = INT_MAX;
        int x2 = 0;
        int y2 = 0;
        for (int j = 0; j < n; j++) {
            if (j == i)
                continue;
            x1 = min(x1, x[j]);
            y1 = min(y1, y[j]);
            x2 = max(x2, x[j]);
            y2 = max(y2, y[j]);
        }
        area[i] = (x2 - x1) * (y2 - y1);
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
        ans = min(ans, area[i]);
    fout << ans << endl;
}
