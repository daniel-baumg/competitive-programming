#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("citystate.in");
    ofstream fout("citystate.out");

    int n;
    fin >> n;
    map<pair<string, string>, int> m;
    for (int i = 0; i < n; i++) {
        string city, state;
        fin >> city >> state;
        m[make_pair(city.substr(0, 2), state)] += 1;
    }

    int ans = 0;
    for (auto p : m) {
        if (p.first.first == p.first.second)
            continue;
        ans += p.second * m[make_pair(p.first.second, p.first.first)];
    }
    fout << ans / 2 << endl;
}
