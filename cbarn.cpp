#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("cbarn.in");
    ofstream fout("cbarn.out");

    int n;
    fin >> n;
    int r[1000];
    for (int i = 0; i < n; i++)
        fin >> r[i];
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int dist = 0;
        for (int j = 0; j < n; j++)
            dist += r[(i + j) % n] * j;
        ans = min(ans, dist);
    }
    fout << ans << endl;
}