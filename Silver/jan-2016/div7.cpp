#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("div7.in");
    ofstream fout("div7.out");

    int n;
    fin >> n;
    int prefix[50001];
    for (int i = 0; i < n; i++) {
        int k;
        fin >> k;
        prefix[i + 1] = (prefix[i] + k) % 7;
    }

    int first[7] = {};
    int last[7] = {};
    for (int i = 0; i < n + 1; i++)
        last[prefix[i]] = i;
    for (int i = n; i >= 0; i--)
        first[prefix[i]] = i;

    int ans = 0;
    for (int i = 0; i < 7; i++)
        ans = max(ans, last[i] - first[i]);
    fout << ans << endl;
}
