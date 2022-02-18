#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("mountains.in");
    ofstream fout("mountains.out");

    int n;
    fin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int x, y;
        fin >> x >> y;
        v.push_back(make_pair(x - y, x + y));
    }
    sort(v.begin(), v.end());

    int ans = 1;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].first == v[cur].first && v[i].second > v[cur].second) {
            cur = i;
        } else if (v[i].second > v[cur].second) {
            ans += 1;
            cur = i;
        }
    }
    fout << ans << endl;
}