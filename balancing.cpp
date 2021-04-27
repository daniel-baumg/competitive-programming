#include <bits/stdc++.h>
using namespace std;

int x[100], y[100];

int m(int n, int cowx, int cowy) {
    int regions[4] = {};
    for (int cow = 0; cow < n; cow++) {
        if (x[cow] < cowx && y[cow] < cowy) regions[0] += 1;
        if (x[cow] < cowx && y[cow] > cowy) regions[1] += 1;
        if (x[cow] > cowx && y[cow] < cowy) regions[2] += 1;
        if (x[cow] > cowx && y[cow] > cowy) regions[3] += 1;
    }
    return max(max(regions[0], regions[1]), max(regions[2], regions[3]));
}

int main() {
    ifstream fin("balancing.in");
    ofstream fout("balancing.out");

    int n, b;
    fin >> n >> b;
    for (int i = 0; i < n; i++)
        fin >> x[i] >> y[i];

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = min(ans, m(n, x[i] + 1, y[j] + 1));
            ans = min(ans, m(n, x[i] + 1, y[j] - 1));
            ans = min(ans, m(n, x[i] - 1, y[j] + 1));
            ans = min(ans, m(n, x[i] - 1, y[j] - 1));
        }
    }
    fout << ans << endl;
}