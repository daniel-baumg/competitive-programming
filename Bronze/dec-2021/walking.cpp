#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string grid[n];
        for (int i = 0; i < n; i++)
            cin >> grid[i];

        int ans1 = 0;
        bool valid1 = true;
        bool valid2 = true;
        for (int i = 0; i < n; i++) {
            valid1 &= grid[i][0] == '.';
            valid1 &= grid[n - 1][i] == '.';
            valid2 &= grid[0][i] == '.';
            valid2 &= grid[i][n - 1] == '.';
        }
        if (valid1) ans1 += 1;
        if (valid2) ans1 += 1;

        int ans2 = 0;
        for (int a = 1; a < n - 1; a++) {
            if (grid[a][0] == 'H')
                break;
            bool valid = true;
            for (int i = 0; i < n; i++)
                valid &= grid[a][i] == '.';
            for (int i = a; i < n; i++)
                valid &= grid[i][n - 1] == '.';
            if (valid)
                ans2 += 1;
        }
        for (int a = 1; a < n - 1; a++) {
            if (grid[0][a] == 'H')
                break;
            bool valid = true;
            for (int i = 0; i < n; i++)
                valid &= grid[i][a] == '.';
            for (int i = a; i < n; i++)
                valid &= grid[n - 1][i] == '.';
            if (valid)
                ans2 += 1;
        }

        int ans3 = 0;
        for (int a = 1; a < n - 1; a++) {
            if (grid[a][0] == 'H')
                break;
            for (int b = 1; b < n - 1; b++) {
                if (grid[a][b] == 'H')
                    break;
                bool valid = true;
                for (int i = a; i < n; i++)
                    valid &= grid[i][b] == '.';
                for (int i = b; i < n; i++)
                    valid &= grid[n - 1][i] == '.';
                if (valid)
                    ans3 += 1;
            }
        }
        for (int a = 1; a < n - 1; a++) {
            if (grid[0][a] == 'H')
                break;
            for (int b = 1; b < n - 1; b++) {
                if (grid[b][a] == 'H')
                    break;
                bool valid = true;
                for (int i = a; i < n; i++)
                    valid &= grid[b][i] == '.';
                for (int i = b; i < n; i++)
                    valid &= grid[i][n - 1] == '.';
                if (valid)
                    ans3 += 1;
            }
        }

        int ans = ans1;
        if (k > 1) ans += ans2;
        if (k > 2) ans += ans3;
        cout << ans << endl;
    }
}