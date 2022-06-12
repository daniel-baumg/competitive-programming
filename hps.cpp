#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("hps.in");
    ofstream fout("hps.out");

    int n, k;
    fin >> n >> k;

    int dp[n + 1][k + 1][3] = {};
    for (int i = 0; i < n; i++) {
        char c;
        fin >> c;
        for (int j = 0; j <= k; j++) {
            dp[i + 1][j][0] = dp[i][j][0];
            dp[i + 1][j][1] = dp[i][j][1];
            dp[i + 1][j][2] = dp[i][j][2];
            if (c == 'H') dp[i + 1][j][0] += 1;
            if (c == 'P') dp[i + 1][j][1] += 1;
            if (c == 'S') dp[i + 1][j][2] += 1;
        }
        for (int j = 1; j <= k; j++) {
            if (c == 'H') dp[i + 1][j - 1][0] = max({dp[i + 1][j - 1][0], dp[i][j][1] + 1, dp[i][j][2] + 1});
            if (c == 'P') dp[i + 1][j - 1][1] = max({dp[i + 1][j - 1][1], dp[i][j][0] + 1, dp[i][j][2] + 1});
            if (c == 'S') dp[i + 1][j - 1][2] = max({dp[i + 1][j - 1][2], dp[i][j][0] + 1, dp[i][j][1] + 1});
        }
    }

    int ans = 0;
    for (int i = 0; i <= k; i++) {
        ans = max(ans, dp[n][i][0]);
        ans = max(ans, dp[n][i][1]);
        ans = max(ans, dp[n][i][2]);
    }
    fout << ans << endl;
}