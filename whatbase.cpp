#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("whatbase.in");
    ofstream fout("whatbase.out");

    int k;
    fin >> k;
    while (k--) {
        string x, y;
        fin >> x >> y;
        int ans1 = 10;
        int ans2 = 10;
        while (true) {
            int a = ans1 * ans1 * (x[0] - '0') + ans1 * (x[1] - '0') + (x[2] - '0');
            int b = ans2 * ans2 * (y[0] - '0') + ans2 * (y[1] - '0') + (y[2] - '0');
            if (a == b) break;
            if (a < b) ans1 += 1;
            if (a > b) ans2 += 1;
        }
        fout << ans1 << " " << ans2 << "\n";
    }
}