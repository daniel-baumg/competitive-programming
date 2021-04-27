#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("backforth.in");
    ofstream fout("backforth.out");

    vector<int> barn1(10), barn2(10);
    int bucket;
    for (int i = 0; i < 10; i++)
        fin >> barn1[i];
    for (int i = 0; i < 10; i++)
        fin >> barn2[i];

    bool possible[2000] = {};
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 11; b++) {
            for (int c = 0; c < 10; c++) {
                for (int d = 0; d < 11; d++) {
                    int milk = 1000;
                    vector<int> b1 = barn1;
                    vector<int> b2 = barn2;
                    milk -= b1[a];
                    b2.push_back(b1[a]);
                    b1.erase(b1.begin() + a);
                    milk += b2[b];
                    b1.push_back(b2[b]);
                    b2.erase(b2.begin() + b);
                    milk -= b1[c];
                    b2.push_back(b1[c]);
                    b1.erase(b1.begin() + c);
                    milk += b2[d];
                    b1.push_back(b2[d]);
                    b2.erase(b2.begin() + d);
                    possible[milk] = true;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 2000; i++)
        if (possible[i])
            ans += 1;

    fout << ans << endl;
}
