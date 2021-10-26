#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("haybales.in");
    ofstream fout("haybales.out");

    int n, q;
    fin >> n >> q;
    vector<int> haybales(n);
    for (int i = 0; i < n; i++)
        fin >> haybales[i];
    sort(haybales.begin(), haybales.end());

    for (int i = 0; i < q; i++) {
        int a, b;
        fin >> a >> b;
        fout << upper_bound(haybales.begin(), haybales.end(), b) - lower_bound(haybales.begin(), haybales.end(), a) << endl;
    }
}
