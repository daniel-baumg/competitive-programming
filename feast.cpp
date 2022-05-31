#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("feast.in");
    ofstream fout("feast.out");

    int t, a, b;
    fin >> t >> a >> b;

    bool possible[t + 1] = {};
    possible[0] = true;
    for (int i = 0; i <= t; i++) {
        if (possible[i] && i + a <= t) possible[i + a] = true;
        if (possible[i] && i + b <= t) possible[i + b] = true;
        if (possible[i])
            possible[i / 2] = true;
    }
    for (int i = 0; i <= t; i++) {
        if (possible[i] && i + a <= t) possible[i + a] = true;
        if (possible[i] && i + b <= t) possible[i + b] = true;
    }

    int ans = t;
    while (!possible[ans])
        ans -= 1;
    fout << ans << endl;
}