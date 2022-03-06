#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<long long, long long>> intervals;

bool valid(long long d) {
    int idx = 0;
    long long cur = intervals[0].first;
    for (int i = 0; i < n; i++) {
        if (cur > intervals[m - 1].second)
            return false;
        cur += d;
        while (idx < m && intervals[idx].second < cur)
            idx += 1;
        if (idx < m)
            cur = max(cur, intervals[idx].first);
    }
    return true;
}

int main() {
    ifstream fin("socdist.in");
    ofstream fout("socdist.out");

    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        long long a, b;
        fin >> a >> b;
        intervals.push_back({a, b});
    }
    sort(intervals.begin(), intervals.end());

    long long ans = 0;
    long long lo = 1;
    long long hi = 1000000000000000000;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (valid(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    fout << ans << endl;
}
