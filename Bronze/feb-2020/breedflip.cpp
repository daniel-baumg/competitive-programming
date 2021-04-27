#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("breedflip.in");
    ofstream fout("breedflip.out");

    int n;
    string a, b;
    fin >> n >> a >> b;
    bool equals[1000];
    for (int i = 0; i < n; i++)
        equals[i] = a[i] == b[i];

    int ans = 0;
    for (int i = 1; i < n; i++)
        if (equals[i] && !equals[i - 1])
            ans += 1;
    fout << ans << endl;
}
