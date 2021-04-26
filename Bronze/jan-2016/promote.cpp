#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("promote.in");
    ofstream fout("promote.out");

    int b[2], s[2], g[2], p[2];
    fin >> b[0] >> b[1] >> s[0] >> s[1] >> g[0] >> g[1] >> p[0] >> p[1];
    int ans[3];
    ans[2] = p[1] - p[0];
    g[1] += p[1] - p[0];
    ans[1] = g[1] - g[0];
    s[1] += g[1] - g[0];
    ans[0] = s[1] - s[0];
    fout << ans[0] << endl << ans[1] << endl << ans[2] << endl;
}
