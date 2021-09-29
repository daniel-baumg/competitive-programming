#include <bits/stdc++.h>
using namespace std;

int mapping[100];

void reverse(int l, int r) {
    int temp[100];
    for (int i = l; i < r + 1; i++)
        temp[i] = mapping[i];
    for (int i = l; i < r + 1; i++)
        mapping[r + l - i] = temp[i];
}

int main() {
    ifstream fin("swap.in");
    ofstream fout("swap.out");

    int n, k, a1, a2, b1, b2;
    fin >> n >> k >> a1 >> a2 >> b1 >> b2;
    for (int i = 0; i < n; i++)
        mapping[i] = i;
    reverse(a1 - 1, a2 - 1);
    reverse(b1 - 1, b2 - 1);

    int len[100];
    fill_n(len, n, 1);
    for (int i = 0; i < n; i++) {
        int idx = i;
        while (mapping[idx] != i) {
            idx = mapping[idx];
            len[i] += 1;
        }
    }

    for (int i = 0; i < n; i++) {
        int ans = i;
        for (int j = 0; j < k % len[i]; j++)
            ans = mapping[ans];
        fout << ans + 1 << endl;
    }
}
