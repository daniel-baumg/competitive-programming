#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("pails.in");
    ofstream fout("pails.out");

    int x, y, m;
    fin >> x >> y >> m;
    int ans = 0;
    for (int i = 0; i < m / x + 1; i++)
        ans = max(ans, i * x + (m - i * x) / y * y);
    fout << ans << endl;
}
