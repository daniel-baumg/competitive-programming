#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("socdist1.in");
    ofstream fout("socdist1.out");

    int n;
    string s;
    fin >> n >> s;

    int dist = 0;
    int cows = 0;
    vector<int> d;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cows += 1;
            d.push_back(dist);
            dist = 0;
        } else {
            dist += 1;
        }
    }
    int d1 = 0;
    int d2 = dist;
    if (!d.empty()) {
        d1 = d[0];
        d.erase(d.begin());
    }
    sort(d.begin(), d.end());

    int ans = 0;
    if (cows > 0) {
        ans = max(ans, d1 / 2);
        ans = max(ans, d2 / 2);
        ans = max(ans, min(d1, d2));
        if (d.size() > 0) ans = max(ans, min(d1, (d[d.size() - 1] + 1) / 2));
        if (d.size() > 0) ans = max(ans, min(d2, (d[d.size() - 1] + 1) / 2));
        if (d.size() > 0) ans = max(ans, (d[d.size() - 1] + 1) / 3);
        if (d.size() > 1) ans = max(ans, (d[d.size() - 2] + 1) / 2);
        for (int i = 0; i < d.size(); i++)
            ans = min(ans, d[i] + 1);
    } else {
        ans = n - 1;
    }
    fout << ans << endl;
}