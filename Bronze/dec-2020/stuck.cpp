#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    char d[n];
    int x[n], y[n];
    for (int i = 0; i < n; i++)
        cin >> d[i] >> x[i] >> y[i];

    priority_queue<tuple<int, int, int, int>> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i] == d[j])
                continue;
            int dx = abs(x[i] - x[j]);
            int dy = abs(y[i] - y[j]);
            if (d[i] == 'E' && x[i] < x[j] && y[i] > y[j] && dx < dy) pq.push({-dy, dx, i, j});
            if (d[i] == 'N' && y[i] < y[j] && x[i] > x[j] && dy < dx) pq.push({-dx, dy, i, j});
        }
    }

    int ans[n] = {};
    bool stuck[n] = {};
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int i = get<2>(cur);
        int j = get<3>(cur);
        if (stuck[j] || (stuck[i] && ans[i] < get<1>(cur)))
            continue;
        stuck[j] = true;
        ans[j] = -get<0>(cur);
    }
    for (int i = 0; i < n; i++) {
        if (stuck[i])
            cout << ans[i] << endl;
        else
            cout << "Infinity" << endl;
    }
}