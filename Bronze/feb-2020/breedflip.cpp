#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("breedflip.in");
    ofstream fout("breedflip.out");

    int n;
    string a, b;
    fin >> n >> a >> b;

    int ans = 0;
    for (int i = 1; i < n; i++)
        if (a[i] == b[i] && a[i - 1] != b[i - 1])
            ans += 1;
    fout << ans << endl;
}
