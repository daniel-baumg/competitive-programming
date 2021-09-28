#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("lemonade.in");
    ofstream fout("lemonade.out");

    int n;
    fin >> n;
    int w[100000];
    for (int i = 0; i < n; i++)
        fin >> w[i];
    sort(w, w + n);

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (ans <= w[n - i - 1])
            ans += 1;
    fout << ans << endl;
}
