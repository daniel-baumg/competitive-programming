#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("cowroute.in");
    ofstream fout("cowroute.out");

    int a, b, n;
    fin >> a >> b >> n;
    vector<int> routes[n];
    int cost[n];
    for (int i = 0; i < n; i++) {
        int m;
        fin >> cost[i] >> m;
        while (m--) {
            int k;
            fin >> k;
            routes[i].push_back(k);
        }
    }

    int ans = -1;
    for (int i = 0; i < n; i++) {
        int idxa = -1;
        int idxb = -1;
        for (int j = 0; j < routes[i].size(); j++) {
            if (routes[i][j] == a) idxa = j;
            if (routes[i][j] == b) idxb = j;
        }
        if (0 <= idxa && idxa < idxb) {
            if (ans < 0)
                ans = cost[i];
            else
                ans = min(ans, cost[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            int idxa = -1;
            int idxb = -1;
            for (int k = 0; k < routes[i].size(); k++) if (routes[i][k] == a) idxa = k;
            for (int k = 0; k < routes[j].size(); k++) if (routes[j][k] == b) idxb = k;
            if (idxa == -1 || idxb == -1)
                continue;
            map<int, int> m1, m2;
            for (int k = idxa + 1; k < routes[i].size(); k++) {
                m1[routes[i][k]] = k;
                m2[routes[i][k]] = -1;
                for (int idx = 0; idx < idxb; idx++)
                    if (routes[j][idx] == routes[i][k])
                        m2[routes[i][k]] = idx;
            }
            bool possible = false;
            for (auto p1 : m1)
                for (auto p2 : m2)
                    possible |= p1.second != -1 && p2.second != -1;
            if (possible) {
                if (ans < 0)
                    ans = cost[i] + cost[j];
                else
                    ans = min(ans, cost[i] + cost[j]);
            }
        }
    }
    fout << ans << endl;
}