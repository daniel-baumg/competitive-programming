#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("marathon.in");
    ofstream fout("marathon.out");

    int n;
    fin >> n;
    int x[100000], y[100000];
    for (int i = 0; i < n; i++)
        fin >> x[i] >> y[i];

    int best = 0;
    for (int i = 1; i < n - 1; i++) {
        int dist1 = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
        int dist2 = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
        int dist3 = abs(x[i + 1] - x[i - 1]) + abs(y[i + 1] - y[i - 1]);
        best = max(best, dist1 + dist2 - dist3);
    }

    int ans = 0;
    for (int i = 1; i < n; i++)
        ans += abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
    ans -= best;
    fout << ans << endl;
}
