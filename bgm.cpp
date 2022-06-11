#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("bgm.in");
    ofstream fout("bgm.out");

    int n;
    fin >> n;
    map<char, map<int, long long>> m;
    for (int i = 0; i < n; i++) {
        char c;
        int k;
        fin >> c >> k;
        m[c][(k + 700000) % 7] += 1;
    }

    long long ans = 0;
    for (auto B : {0, 1, 2, 3, 4, 5, 6})
        for (auto E : {0, 1, 2, 3, 4, 5, 6})
            for (auto S : {0, 1, 2, 3, 4, 5, 6})
                for (auto I : {0, 1, 2, 3, 4, 5, 6})
                    for (auto G : {0, 1, 2, 3, 4, 5, 6})
                        for (auto O : {0, 1, 2, 3, 4, 5, 6})
                            for (auto M : {0, 1, 2, 3, 4, 5, 6})
                                if ((B + E + S + S + I + E) * (G + O + E + S) * (M + O + O) % 7 == 0)
                                    ans += m['B'][B] * m['E'][E] * m['S'][S] * m['I'][I] * m['G'][G] * m['O'][O] * m['M'][M];
   fout << ans << endl;
}