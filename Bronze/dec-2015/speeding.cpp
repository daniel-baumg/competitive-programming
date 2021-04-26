#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("speeding.in");
    ofstream fout("speeding.out");

    int n, m;
    fin >> n >> m;
    vector<int> speed_limit, speed_bessie;
    for (int i = 0; i < n; i++) {
        int len, speed;
        fin >> len >> speed;
        for (int j = 0; j < len; j++)
            speed_limit.push_back(speed);
    }
    for (int i = 0; i < m; i++) {
        int len, speed;
        fin >> len >> speed;
        for (int j = 0; j < len; j++)
            speed_bessie.push_back(speed);
    }

    int ans = 0;
    for (int i = 0; i < 100; i++)
        ans = max(ans, speed_bessie[i] - speed_limit[i]);

    fout << ans << endl;
}
