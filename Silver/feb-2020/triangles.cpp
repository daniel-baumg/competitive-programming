#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");

    int n;
    fin >> n;
    map<pair<int, int>, int> id;
    map<int, set<int>> m1, m2;
    for (int i = 0; i < n; i++) {
        int x, y;
        fin >> x >> y;
        id[{x, y}] = i;
        m1[y].insert(x);
        m2[x].insert(y);
    }

    long long dx[n] = {};
    for (auto p : m1) {
        int x = *p.second.begin();
        int cur = 0;
        for (auto i : p.second)
            cur += i - x;
        dx[id[{x, p.first}]] = cur;
        int idx = 0;
        for (auto i : p.second) {
            if (i == *p.second.begin())
                continue;
            idx += 1;
            cur += (i - x) * idx;
            cur -= (i - x) * (p.second.size() - idx);
            dx[id[{i, p.first}]] = cur;
            x = i;
        }
    }

    long long dy[n] = {};
    for (auto p : m2) {
        int y = *p.second.begin();
        int cur = 0;
        for (auto i : p.second)
            cur += i - y;
        dy[id[{p.first, y}]] = cur;
        int idx = 0;
        for (auto i : p.second) {
            if (i == *p.second.begin())
                continue;
            idx += 1;
            cur += (i - y) * idx;
            cur -= (i - y) * (p.second.size() - idx);
            dy[id[{p.first, i}]] = cur;
            y = i;
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dx[i] * dy[i];
        ans %= 1000000007;
    }
    fout << ans << endl;
}