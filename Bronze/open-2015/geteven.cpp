#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("geteven.in");
    ofstream fout("geteven.out");

    int n;
    fin >> n;
    map<char, map<int, long long>> m;
    for (int i = 0; i < n; i++) {
        char c;
        int k;
        fin >> c >> k;
        m[c][(k + 300) % 2] += 1;
    }

    long long ans = 0;
    for (auto B : {0, 1})
        for (auto E : {0, 1})
            for (auto S : {0, 1})
                for (auto I : {0, 1})
                    for (auto G : {0, 1})
                        for (auto O : {0, 1})
                            for (auto M : {0, 1})
                                if ((B + E + S + S + I + E) * (G + O + E + S) * (M + O + O) % 2 == 0)
                                    ans += m['B'][B] * m['E'][E] * m['S'][S] * m['I'][I] * m['G'][G] * m['O'][O] * m['M'][M];
   fout << ans << endl;
}
