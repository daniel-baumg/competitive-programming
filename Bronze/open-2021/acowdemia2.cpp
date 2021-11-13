#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    string lab[100];
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        cin >> lab[i];
        m[lab[i]] = i;
    }
    sort(lab, lab + n);

    char ans[100][100] = {};
    for (int i = 0; i < n; i++) {
        fill_n(ans[i], n, '?');
        ans[i][i] = 'B';
    }

    for (int i = 0; i < k; i++) {
        string order[100];
        for (int j = 0; j < n; j++)
            cin >> order[j];
        int cur = 0;
        for (int j = 0; j < n - 1; j++) {
            int p1 = lower_bound(lab, lab + n, order[j]) - lab;
            int p2 = lower_bound(lab, lab + n, order[j + 1]) - lab;
            if (p1 < p2) {
                cur = j + 1;
            } else {
                for (int x = 0; x < cur + 1; x++) {
                    for (int y = cur + 1; y < n; y++) {
                        ans[m[order[x]]][m[order[y]]] = '0';
                        ans[m[order[y]]][m[order[x]]] = '1';
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << ans[i][j];
        cout << endl;
    }
}