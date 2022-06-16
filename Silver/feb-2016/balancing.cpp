#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("balancing.in");
    ofstream fout("balancing.out");

    int n;
    fin >> n;
    map<int, vector<int>> m1, m2;
    for (int i = 0; i < n; i++) {
        int x, y;
        fin >> x >> y;
        m1[x].push_back(y);
        m2[y].push_back(x);
    }
    for (auto p : m1) sort(m1[p.first].begin(), m1[p.first].end());
    for (auto p : m2) sort(m2[p.first].begin(), m2[p.first].end());

    int ans = n;
    int k = 0;
    for (auto p1 : m1) {
        k += p1.second.size();
        int a1 = k;
        int a2 = n - k;
        int a3 = 0;
        int a4 = 0;
        for (auto p2 : m2) {
            int cur = upper_bound(p2.second.begin(), p2.second.end(), p1.first) - p2.second.begin();
            a1 -= cur;
            a2 -= p2.second.size() - cur;
            a3 += cur;
            a4 += p2.second.size() - cur;
            ans = min(ans, max({a1, a2, a3, a4}));
        }
    }
    fout << ans << endl;
}