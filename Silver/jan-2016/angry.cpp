#include <bits/stdc++.h>
using namespace std;

int n;
int x[50000];

int cows(int r) {
    queue<int> q;
    for (int i = 0; i < n; i++)
        q.push(x[i]);
    int result = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        while (!q.empty() && q.front() - cur <= 2 * r)
            q.pop();
        result += 1;
    }
    return result;
}

int main() {
    ifstream fin("angry.in");
    ofstream fout("angry.out");

    int k;
    fin >> n >> k;
    for (int i = 0; i < n; i++)
        fin >> x[i];
    sort(x, x + n);

    int ans = 0;
    int lo = 1;
    int hi = 1000000000;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (cows(mid) <= k) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    fout << ans << endl;
}