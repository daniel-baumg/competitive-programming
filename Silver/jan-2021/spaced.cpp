#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[1000][1000];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    int sum1[1000] = {};
    int sum2[1000] = {};
    int sum3[1000] = {};
    int sum4[1000] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i % 2 == 0) sum1[j] += a[i][j];
            if (i % 2 == 1) sum2[j] += a[i][j];
            if (j % 2 == 0) sum3[i] += a[i][j];
            if (j % 2 == 1) sum4[i] += a[i][j];
        }
    }

    int ans1 = 0;
    int ans2 = 0;
    for (int i = 0; i < n; i++) {
        ans1 += max(sum1[i], sum2[i]);
        ans2 += max(sum3[i], sum4[i]);
    }
    cout << max(ans1, ans2) << endl;
}