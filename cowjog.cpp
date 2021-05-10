#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("cowjog.in");
    ofstream fout("cowjog.out");

    int n;
    fin >> n;
    int cows[100000][2];
    for (int i = 0; i < n; i++)
        fin >> cows[i][0] >> cows[i][1];

    int ans = 0;
    int min_speed = INT_MAX;
    for (int i = n - 1; i >= 0; i--) {
        min_speed = min(min_speed, cows[i][1]);
        if (cows[i][1] <= min_speed)
            ans += 1;
    }
    fout << ans << endl;
}