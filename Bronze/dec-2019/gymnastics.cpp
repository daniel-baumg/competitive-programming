#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("gymnastics.in");
    ofstream fout("gymnastics.out");

    int k, n;
    fin >> k >> n;
    int rankings[10][20];
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            fin >> rankings[i][j];

    int ans = 0;
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            if (a == b)
                continue;
            bool consistent = true;
            for (int i = 0; i < k; i++) {
                int idxA = 0;
                int idxB = 0;
                for (int j = 0; j < n; j++) {
                    if (rankings[i][j] == a + 1) idxA = j;
                    if (rankings[i][j] == b + 1) idxB = j;
                }
                consistent &= idxA < idxB;
            }
            if (consistent)
                ans += 1;
        }
    }
    fout << ans << endl;
}
