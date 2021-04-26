#include <bits/stdc++.h>
using namespace std;

void swap(int a, int b, bool arr[]) {
    bool temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

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
        swap(a - 1, b - 1, pebble[0]);
        swap(a - 1, b - 1, pebble[1]);
        swap(a - 1, b - 1, pebble[2]);
        if (pebble[0][guess - 1])
            ans[0] += 1;
        if (pebble[1][guess - 1])
            ans[1] += 1;
        if (pebble[2][guess - 1])
            ans[2] += 1;
    }
    fout << max(max(ans[0], ans[1]), ans[2]) << endl;
}
