#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("maxcross.in");
    ofstream fout("maxcross.out");

    int n, k, b;
    fin >> n >> k >> b;
    bool broken[100001] = {};
    for (int i = 0; i < b; i++) {
        int crosswalk;
        fin >> crosswalk;
        broken[crosswalk] = true;
    }
    int prefix[100001];
    prefix[0] = 0;
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + broken[i + 1];

    int ans = b;
    for (int i = 0; i <= n - k; i++)
        ans = min(ans, prefix[i + k] - prefix[i]);
    fout << ans << endl;
}