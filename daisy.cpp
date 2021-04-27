#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int p[100];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            double avg = 0;
            for (int k = i; k < j + 1; k++)
                avg += p[k];
            avg /= j - i + 1;
            for (int k = i; k < j + 1; k++) {
                if (p[k] == avg) {
                    ans += 1;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}