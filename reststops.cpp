#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("reststops.in");
    ofstream fout("reststops.out");

    long long l, n, rf, rb;
    fin >> l >> n >> rf >> rb;
    priority_queue<pair<long long, long long>> pq;
    for (int i = 0; i < n; i++) {
        int x, c;
        fin >> x >> c;
        pq.push({c, x});
    }

    long long ans = 0;
    long long xf = 0;
    long long xb = 0;
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (cur.second < xb)
            continue;
        ans += cur.first * ((cur.second - xf) * rf - (cur.second - xb) * rb);
        xf = cur.second;
        xb = cur.second;
    }
    fout << ans << endl;
}