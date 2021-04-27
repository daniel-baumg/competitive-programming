#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("taming.in");
    ofstream fout("taming.out");

    int n;
    fin >> n;
    int log[100];
    for (int i = 0; i < n; i++)
        fin >> log[i];
    bool possible = true;
    for (int i = n - 1; i > 0; i--) {
        if (log[i] > 0) {
            while (i > 0 && log[i] > 0) {
                if (log[i - 1] != -1 && log[i - 1] != log[i] - 1)
                    possible = false;
                log[i - 1] = log[i] - 1;
                i--;
            }
        }
    }
    if (log[0] > 0)
        possible = false;
    log[0] = 0;

    if (possible) {
        int ans[2] = {};
        for (int i = 0; i < n; i++) {
            if (log[i] == 0)
                ans[0] += 1;
            if (log[i] == -1)
                ans[1] += 1;
        }
        fout << ans[0] << " " << ans[0] + ans[1] << endl;
    } else {
        fout << -1 << endl;
    }
}
