#include <bits/stdc++.h>
using namespace std;

int n;
int d[10000];

int t(int k) {
    int active[10000] = {};
    for (int i = 0; i < k; i++)
        active[i] = d[i];
    queue<int> q;
    for (int i = k; i < n; i++)
        q.push(d[i]);
    int result = 0;
    while (!q.empty()) {
        int change = INT_MAX;
        for (int i = 0; i < k; i++)
            change = min(change, active[i]);
        for (int i = 0; i < k; i++)
            active[i] -= change;
        for (int i = 0; i < k; i++) {
            if (active[i] == 0 && !q.empty()) {
                active[i] = q.front();
                q.pop();
            }
        }
        result += change;
    }
    int change = 0;
    for (int i = 0; i < k; i++)
        change = max(change, active[i]);
    result += change;
    return result;
}

int main() {
    ifstream fin("cowdance.in");
    ofstream fout("cowdance.out");

    int tmax;
    fin >> n >> tmax;
    for (int i = 0; i < n; i++)
        fin >> d[i];

    int ans = 0;
    int lo = 1;
    int hi = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (t(mid) <= tmax) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    fout << ans << endl;
}