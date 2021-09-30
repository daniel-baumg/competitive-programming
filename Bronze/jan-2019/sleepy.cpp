#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("sleepy.in");
    ofstream fout("sleepy.out");

    int n;
    fin >> n;
    int p[100];
    for (int i = 0; i < n; i++)
        fin >> p[i];

    int ans = n - 1;
    while (ans > 0 && p[ans] > p[ans - 1])
        ans -= 1;
    fout << ans << endl;
}