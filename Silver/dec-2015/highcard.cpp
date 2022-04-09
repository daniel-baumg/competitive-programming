#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("highcard.in");
    ofstream fout("highcard.out");

    int n;
    fin >> n;
    bool elsie[100001] = {};
    for (int i = 0; i < n; i++) {
        int card;
        fin >> card;
        elsie[card] = true;
    }

    vector<int> e, b;
    for (int i = 1; i <= 2 * n; i++) {
        if (elsie[i])
            e.push_back(i);
        else
            b.push_back(i);
    }

    int ans = 0;
    int idxE = 0;
    int idxB = 0;
    while (idxE < n) {
        while (idxB < n) {
            if (b[idxB] > e[idxE]) {
                ans += 1;
                idxB += 1;
                break;
            }
            idxB += 1;
        }
        idxE += 1;
    }
    fout << ans << endl;
}
