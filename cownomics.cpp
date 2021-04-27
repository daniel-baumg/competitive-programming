#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");

    int n, m;
    fin >> n >> m;
    string genomes[1000];
    for (int i = 0; i < 2 * n; i++)
        fin >> genomes[i];
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                set<int> genes;
                bool valid = true;
                for (int x = 0; x < 2 * n; x++) {
                    int s = 0;
                    s += 10000 * genomes[x][i];
                    s += 100 * genomes[x][j];
                    s += genomes[x][k];
                    if (x < n) {
                        genes.insert(s);
                    } else if (genes.count(s) > 0) {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                    ans += 1;
            }
        }
    }
    fout << ans << endl;
}