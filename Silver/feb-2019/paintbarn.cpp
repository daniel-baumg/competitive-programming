#include <bits/stdc++.h>
using namespace std;

int barn[1001][1001];
int prefix[1001][1001];

int main() {
    ifstream fin("paintbarn.in");
    ofstream fout("paintbarn.out");

    int n, k;
    fin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;
        barn[x1][y1] += 1;
        barn[x2][y2] += 1;
        barn[x1][y2] -= 1;
        barn[x2][y1] -= 1;
    }

    for (int i = 1; i < 1001; i++)
        for (int j = 1; j < 1001; j++)
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + barn[i - 1][j - 1];

    int ans = 0;
    for (int i = 0; i < 1001; i++)
        for (int j = 0; j < 1001; j++)
            if (prefix[i][j] == k)
                ans += 1;
    fout << ans << endl;
}
