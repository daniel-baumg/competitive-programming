#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");

    int n, k;
    fin >> n >> k;
    int d[1000];
    for (int i = 0; i < n; i++)
        fin >> d[i];
    sort(d, d + n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int idx = i;
        while (idx < n && d[idx] - d[i] <= k)
            idx += 1;
        ans = max(ans, idx - i);
    }
    fout << ans << endl;
}
