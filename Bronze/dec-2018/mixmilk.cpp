#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");

    int c[3], m[3];
    fin >> c[0] >> m[0] >> c[1] >> m[1] >> c[2] >> m[2];
    for (int i = 0; i < 100; i++) {
        int from = i % 3;
        int to = (i + 1) % 3;
        if (m[from] + m[to] > c[to]) {
            m[from] = m[to] + m[from] - c[to];
            m[to] = c[to];
        } else {
            m[to] = m[from] + m[to];
            m[from] = 0;
        }
    }
    fout << m[0] << endl << m[1] << endl << m[2] << endl;
}
