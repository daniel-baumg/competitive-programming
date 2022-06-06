#include <bits/stdc++.h>
using namespace std;

long long id(long long a, long long b) { return 1000000 * a + b; }

long long id(long long a, long long b, long long c) { return 1000000000000 * a + 1000000 * b + c; }

int main() {
    ifstream fin("cowpatibility.in");
    ofstream fout("cowpatibility.out");

    long long n;
    fin >> n;
    long long a[n][5];
    unordered_map<long long, long long> m1, m2, m3;
    map<pair<long long, long long>, long long> m4, m5;
    for (int i = 0; i < n; i++) {
        fin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
        sort(a[i], a[i] + 5);
        m1[a[i][0]] += 1;
        m1[a[i][1]] += 1;
        m1[a[i][2]] += 1;
        m1[a[i][3]] += 1;
        m1[a[i][4]] += 1;
        m2[id(a[i][0], a[i][1])] += 1;
        m2[id(a[i][0], a[i][2])] += 1;
        m2[id(a[i][0], a[i][3])] += 1;
        m2[id(a[i][0], a[i][4])] += 1;
        m2[id(a[i][1], a[i][2])] += 1;
        m2[id(a[i][1], a[i][3])] += 1;
        m2[id(a[i][1], a[i][4])] += 1;
        m2[id(a[i][2], a[i][3])] += 1;
        m2[id(a[i][2], a[i][4])] += 1;
        m2[id(a[i][3], a[i][4])] += 1;
        m3[id(a[i][0], a[i][1], a[i][2])] += 1;
        m3[id(a[i][0], a[i][1], a[i][3])] += 1;
        m3[id(a[i][0], a[i][1], a[i][4])] += 1;
        m3[id(a[i][0], a[i][2], a[i][3])] += 1;
        m3[id(a[i][0], a[i][2], a[i][4])] += 1;
        m3[id(a[i][0], a[i][3], a[i][4])] += 1;
        m3[id(a[i][1], a[i][2], a[i][3])] += 1;
        m3[id(a[i][1], a[i][2], a[i][4])] += 1;
        m3[id(a[i][1], a[i][3], a[i][4])] += 1;
        m3[id(a[i][2], a[i][3], a[i][4])] += 1;
        m4[{id(a[i][0], a[i][1]), id(a[i][2], a[i][3])}] += 1;
        m4[{id(a[i][0], a[i][1]), id(a[i][2], a[i][4])}] += 1;
        m4[{id(a[i][0], a[i][1]), id(a[i][3], a[i][4])}] += 1;
        m4[{id(a[i][0], a[i][2]), id(a[i][3], a[i][4])}] += 1;
        m4[{id(a[i][1], a[i][2]), id(a[i][3], a[i][4])}] += 1;
        m5[{id(a[i][0], a[i][1], a[i][2]), id(a[i][3], a[i][4])}] += 1;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long valid = 0;
        valid += m1[a[i][0]];
        valid += m1[a[i][1]];
        valid += m1[a[i][2]];
        valid += m1[a[i][3]];
        valid += m1[a[i][4]];
        valid -= m2[id(a[i][0], a[i][1])];
        valid -= m2[id(a[i][0], a[i][2])];
        valid -= m2[id(a[i][0], a[i][3])];
        valid -= m2[id(a[i][0], a[i][4])];
        valid -= m2[id(a[i][1], a[i][2])];
        valid -= m2[id(a[i][1], a[i][3])];
        valid -= m2[id(a[i][1], a[i][4])];
        valid -= m2[id(a[i][2], a[i][3])];
        valid -= m2[id(a[i][2], a[i][4])];
        valid -= m2[id(a[i][3], a[i][4])];
        valid += m3[id(a[i][0], a[i][1], a[i][2])];
        valid += m3[id(a[i][0], a[i][1], a[i][3])];
        valid += m3[id(a[i][0], a[i][1], a[i][4])];
        valid += m3[id(a[i][0], a[i][2], a[i][3])];
        valid += m3[id(a[i][0], a[i][2], a[i][4])];
        valid += m3[id(a[i][0], a[i][3], a[i][4])];
        valid += m3[id(a[i][1], a[i][2], a[i][3])];
        valid += m3[id(a[i][1], a[i][2], a[i][4])];
        valid += m3[id(a[i][1], a[i][3], a[i][4])];
        valid += m3[id(a[i][2], a[i][3], a[i][4])];
        valid -= m4[{id(a[i][0], a[i][1]), id(a[i][2], a[i][3])}];
        valid -= m4[{id(a[i][0], a[i][1]), id(a[i][2], a[i][4])}];
        valid -= m4[{id(a[i][0], a[i][1]), id(a[i][3], a[i][4])}];
        valid -= m4[{id(a[i][0], a[i][2]), id(a[i][3], a[i][4])}];
        valid -= m4[{id(a[i][1], a[i][2]), id(a[i][3], a[i][4])}];
        valid += m5[{id(a[i][0], a[i][1], a[i][2]), id(a[i][3], a[i][4])}];
        ans += n - valid;
    }
    ans /= 2;
    fout << ans << endl;
}