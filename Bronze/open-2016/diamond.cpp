#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");

    int n, k;
    fin >> n >> k;
    int diamonds[1000];
    for (int i = 0; i < n; i++)
        fin >> diamonds[i];
    sort(diamonds, diamonds + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int idx = i;
        while (idx < n && diamonds[idx] - diamonds[i] <= k)
            idx += 1;
        ans = max(ans, idx - i);
    }
    fout << ans << endl;
}
