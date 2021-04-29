#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");

    int n, m;
    fin >> n >> m;
    string genomes[200];
    for (int i = 0; i < 2 * n; i++)
        fin >> genomes[i];

    int ans = 0;
    for (int i = 0; i < m; i++) {
        set<char> spots, plain;
        for (int j = 0; j < n; j++)
            spots.insert(genomes[j][i]);
        for (int j = 0; j < n; j++)
            plain.insert(genomes[n + j][i]);
        bool valid = true;
        valid &= spots.count('A') + plain.count('A') < 2;
        valid &= spots.count('C') + plain.count('C') < 2;
        valid &= spots.count('G') + plain.count('G') < 2;
        valid &= spots.count('T') + plain.count('T') < 2;
        if (valid)
            ans += 1;
    }
    fout << ans << endl;
}
