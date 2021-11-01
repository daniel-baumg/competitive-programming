#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("shell.in");
    ofstream fout("shell.out");

    int n;
    fin >> n;
    int ans[3] = {};
    bool pebble[3][3] = {};
    pebble[0][0] = true;
    pebble[1][1] = true;
    pebble[2][2] = true;
    for (int i = 0; i < n; i++) {
        int a, b, guess;
        fin >> a >> b >> guess;
        swap(pebble[0][a - 1], pebble[0][b - 1]);
        swap(pebble[1][a - 1], pebble[1][b - 1]);
        swap(pebble[2][a - 1], pebble[2][b - 1]);
        if (pebble[0][guess - 1]) ans[0] += 1;
        if (pebble[1][guess - 1]) ans[1] += 1;
        if (pebble[2][guess - 1]) ans[2] += 1;
    }
    fout << max(max(ans[0], ans[1]), ans[2]) << endl;
}
