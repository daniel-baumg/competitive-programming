#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("cow.in");
    ofstream fout("cow.out");

    int n;
    string s;
    fin >> n >> s;

    long long c = 0;
    long long co = 0;
    long long cow = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'C') c += 1;
        if (s[i] == 'O') co += c;
        if (s[i] == 'W') cow += co;
    }
    fout << cow << endl;
}
