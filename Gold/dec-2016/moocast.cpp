#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");

    int n;
    fin >> n;
    int x[1000], y[1000];
    for (int i = 0; i < n; i++)
        fin >> x[i] >> y[i];

    int ans = 0;
    int lo = 1;
    int hi = 1250000000;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        bool visited[1000] = {};
        visited[0] = true;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < n; i++) {
                if (i == cur)
                    continue;
                if (pow(x[i] - x[cur], 2) + pow(y[i] - y[cur], 2) <= mid && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        bool valid = true;
        for (int i = 0; i < n; i++)
            valid &= visited[i];
        if (valid) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    fout << ans << endl;
}
