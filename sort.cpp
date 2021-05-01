#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("sort.in");
    ofstream fout("sort.out");

    int n;
    fin >> n;
    int a[100000];
    for (int i = 0; i < n; i++)
        fin >> a[i];

    int b[100000];
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    sort(b, b + n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int hi = upper_bound(b, b + n, a[i]) - b - 1;
        if (hi <= i)
            ans = max(ans, abs(hi - i) + 1);
    }
    fout << ans << endl;
}