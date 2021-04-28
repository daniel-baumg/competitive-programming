#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("herding.in");
    ofstream fout("herding.out");

    int cows[3];
    fin >> cows[0] >> cows[1] >> cows[2];
    sort(cows, cows + 3);
    if (cows[0] + 1 == cows[1] && cows[1] + 1 == cows[2])
        fout << 0 << endl;
    else if (cows[0] + 2 == cows[1] || cows[1] + 2 == cows[2])
        fout << 1 << endl;
    else
        fout << 2 << endl;

    int ans = 0;
    while (cows[0] + 1 != cows[1] || cows[1] + 1 != cows[2]) {
        ans += 1;
        if (cows[2] - cows[1] < cows[1] - cows[0]) {
            cows[2] = cows[1];
            cows[1] = cows[2] - 1;
        } else {
            cows[0] = cows[1];
            cows[1] = cows[0] + 1;
        }
    }
    fout << ans << endl;
}
