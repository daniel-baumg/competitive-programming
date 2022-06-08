#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> intervals;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        char c;
        int p;
        cin >> c >> p;
        if (c == 'G') intervals.push_back({p, 1000000000});
        if (c == 'L') intervals.push_back({0, p});
        pq.push({-intervals[i].first, i});
        pq.push({-intervals[i].second, i});
    }

    int ans = n;
    int position = 0;
    set<int> active;
    while (!pq.empty()) {
        set<int> s;
        position = pq.top().first;
        while (!pq.empty() && pq.top().first == position) {
            auto cur = pq.top();
            pq.pop();
            if (intervals[cur.second].first == -cur.first)
                active.insert(cur.second);
            else
                s.insert(cur.second);
        }
        ans = min(ans, n - int(active.size()));
        for (int i : s)
            active.erase(i);
    }
    cout << ans << endl;
}