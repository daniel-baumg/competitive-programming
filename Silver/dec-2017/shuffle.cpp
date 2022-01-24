#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");

    int n;
    fin >> n;
    int a[100000];
    map<int, set<int>> m;
    for (int i = 0; i < n; i++) {
        fin >> a[i];
        a[i] -= 1;
        m[a[i]].insert(i);
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (m[i].size() == 0)
            q.push(i);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        m[a[cur]].erase(cur);
        if (m[a[cur]].size() == 0)
            q.push(a[cur]);
    }

    int ans = 0;
    for (auto p : m)
        if (p.second.size() > 0)
            ans += 1;
    fout << ans << endl;
}
