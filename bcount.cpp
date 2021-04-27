#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("bcount.in");
    ofstream fout("bcount.out");

    int n, q;
    fin >> n >> q;
    int prefix[100001][3] = {};
    for (int i = 0; i < n; i++) {
        int k;
        fin >> k;
        prefix[i + 1][0] = prefix[i][0];
        prefix[i + 1][1] = prefix[i][1];
        prefix[i + 1][2] = prefix[i][2];
        prefix[i + 1][k - 1] += 1;
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        fin >> a >> b;
        fout << prefix[b][0] - prefix[a - 1][0] << " ";
        fout << prefix[b][1] - prefix[a - 1][1] << " ";
        fout << prefix[b][2] - prefix[a - 1][2] << endl;
    }
}