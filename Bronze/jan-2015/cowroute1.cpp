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
    fout << ans << endl;
}
