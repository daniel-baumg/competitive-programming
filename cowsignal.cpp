#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("cowsignal.in");
    ofstream fout("cowsignal.out");

    int m, n, k;
    fin >> m >> n >> k;
    char signal[10][10], result[100][100];
    for (int i = 0; i < m; i++) {
        string line;
        fin >> line;
        for (int j = 0; j < n; j++)
            for (int x = i * k; x < i * k + k; x++)
                for (int y = j * k; y < j * k + k; y++)
                    result[x][y] = line[j];
    }

    for (int i = 0; i < m * k; i++) {
        for (int j = 0; j < n * k; j++)
            fout << result[i][j];
        fout << endl;
    }
}