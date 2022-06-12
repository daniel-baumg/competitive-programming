#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("sort.in");
    ofstream fout("sort.out");

    int n;
    fin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        fin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int hi = upper_bound(b, b + n, a[i]) - b - 1;
        if (hi <= i)
            ans = max(ans, i - hi + 1);
    }
    fout << ans << endl;
}
