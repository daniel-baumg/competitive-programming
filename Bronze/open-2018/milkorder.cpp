#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("milkorder.in");
    ofstream fout("milkorder.out");

    int n, m, k;
    fin >> n >> m >> k;
    bool in_hierarchy = false;
    deque<int> d;
    for (int i = 0; i < m; i++) {
        int cow;
        fin >> cow;
        d.push_back(cow);
        if (cow == 1)
            in_hierarchy = true;
    }
    int order[100] = {};
    set<int> fixed;
    for (int i = 0; i < k; i++) {
        int c, p;
        fin >> c >> p;
        order[p - 1] = c;
        fixed.insert(c);
    }

    if (in_hierarchy) {
        int idx = 0;
        while (!d.empty()) {
            int cur = d.front();
            d.pop_front();
            if (fixed.count(cur) == 1) {
                while (order[idx] != cur)
                    idx += 1;
            } else {
                while (order[idx] != 0)
                    idx += 1;
                order[idx] = cur;
            }
        }
    } else {
        int idx = n - 1;
        while (!d.empty()) {
            int cur = d.back();
            d.pop_back();
            if (fixed.count(cur) == 1) {
                while (order[idx] != cur)
                    idx -= 1;
            } else {
                while (order[idx] != 0)
                    idx -= 1;
                order[idx] = cur;
            }
        }
    }

    int ans = -1;
    for (int i = 0; i < n; i++)
        if (order[i] == 1)
            ans = i + 1;
    if (ans == -1) {
        for (int i = 0; i < n; i++) {
            if (order[i] == 0) {
                ans = i + 1;
                break;
            }
        }
    }
    fout << ans << endl;
}
