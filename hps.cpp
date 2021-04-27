#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("hps.in");
    ofstream fout("hps.out");

    int n;
    fin >> n;
    int games[3][3] = {};
    for (int i = 0; i < n; i++) {
        int a, b;
        fin >> a >> b;
        games[a - 1][b - 1] += 1;
    }

    fout << max(games[0][1] + games[1][2] + games[2][0], games[1][0] + games[2][1] + games[0][2]) << endl;
}