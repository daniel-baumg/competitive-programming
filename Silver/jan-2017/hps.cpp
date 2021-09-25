#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("hps.in");
    ofstream fout("hps.out");

    int n;
    fin >> n;
    int h[100001], p[100001], s[100001];
    h[0] = 0;
    p[0] = 0;
    s[0] = 0;
    for (int i = 0; i < n; i++) {
        string gesture;
        fin >> gesture;
        h[i + 1] = h[i];
        p[i + 1] = p[i];
        s[i + 1] = s[i];
        if (gesture == "H") h[i + 1] += 1;
        if (gesture == "P") p[i + 1] += 1;
        if (gesture == "S") s[i + 1] += 1;
    }

    int ans = 0;
    for (int i = 0; i < n + 1; i++) {
        ans = max(ans, h[i] + p[n] - p[i]);
        ans = max(ans, p[i] + h[n] - h[i]);
        ans = max(ans, h[i] + s[n] - s[i]);
        ans = max(ans, s[i] + h[n] - h[i]);
        ans = max(ans, p[i] + s[n] - s[i]);
        ans = max(ans, s[i] + p[n] - p[i]);
    }
    fout << ans << endl;
}
