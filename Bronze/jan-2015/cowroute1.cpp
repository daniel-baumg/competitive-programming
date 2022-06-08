#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("cowroute.in");
    ofstream fout("cowroute.out");

    int a, b, n;
    fin >> a >> b >> n;

    int ans = -1;
    while (n--) {
        int cost, m;
        fin >> cost >> m;
        int route[m];
        for (int i = 0; i < m; i++)
            fin >> route[i];
        int idxa = -1;
        int idxb = -1;
        for (int i = 0; i < m; i++) {
            if (route[i] == a) idxa = i;
            if (route[i] == b) idxb = i;
        }
        if (idxa >= 0 && idxa < idxb) {
            if (ans < 0)
                ans = cost;
            else
                ans = min(ans, cost);
        }
    }
    fout << ans << endl;
}