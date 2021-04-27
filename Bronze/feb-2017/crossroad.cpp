#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("crossroad.in");
    ofstream fout("crossroad.out");

    int n;
    fin >> n;
    int log[10];
    fill_n(log, 10, -1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cow, side;
        fin >> cow >> side;
        if (log[cow - 1] != -1 && log[cow - 1] != side)
            ans += 1;
        log[cow - 1] = side;
    }
    fout << ans << endl;
}
