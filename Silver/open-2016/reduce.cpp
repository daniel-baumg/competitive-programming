#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("reduce.in");
    ofstream fout("reduce.out");

    int n;
    fin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; i++)
        fin >> x[i] >> y[i];
    vector<pair<pair<int, int>, int>> v[4];
    for (int i = 0; i < n; i++) {
        v[0].push_back({{x[i], y[i]}, i});
        v[1].push_back({{y[i], x[i]}, i});
        v[2].push_back({{-x[i], y[i]}, i});
        v[3].push_back({{-y[i], x[i]}, i});
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    sort(v[2].begin(), v[2].end());
    sort(v[3].begin(), v[3].end());

    int ans = 2000000000;
    for (int a = 0; a <= 3; a++) {
        for (int b = 0; b <= 3; b++) {
            for (int c = 0; c <= 3; c++) {
                for (int d = 0; d <= 3; d++) {
                    if (a + b + c + d != 3)
                        continue;
                    int k[4] = {a, a + b, a + b + c, a + b + c + d};
                    set<int> s;
                    for (int i = 0; i < 4; i++) {
                        int cur = 0;
                        while (s.size() < k[i]) {
                            s.insert(v[i][cur].second);
                            cur += 1;
                        }
                    }
                    int mxx = 0;
                    int mxy = 0;
                    int mnx = 50000;
                    int mny = 50000;
                    for (int i = 0; i < n; i++) {
                        if (s.count(i) == 0) {
                            mxx = max(mxx, x[i]);
                            mxy = max(mxy, y[i]);
                            mnx = min(mnx, x[i]);
                            mny = min(mny, y[i]);
                        }
                    }
                    ans = min(ans, (mxx - mnx) * (mxy - mny));
                }
            }
        }
    }
    fout << ans << endl;
}