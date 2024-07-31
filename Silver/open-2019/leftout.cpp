#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("leftout.in");
    ofstream fout("leftout.out");

    int n;
    fin >> n;
    string s[n];
    for (int i = 0; i < n; i++)
        fin >> s[i];

    for (int i = 1; i < n; i++)
        if (s[i][0] == s[0][0])
            for (int j = 0; j < n; j++)
                s[i][j] = 'L' + 'R' - s[i][j];
    for (int i = 1; i < n; i++)
        if (s[0][i] == s[0][0])
            for (int j = 0; j < n; j++)
                s[j][i] = 'L' + 'R' - s[j][i];
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (s[i][j] == s[0][0])
                v.push_back({i, j});
    if (v.size() == 1) {
        fout << 1 << " " << 1 << endl;
        return 0;
    }

    for (int i = 1; i < n; i++)
        if (s[i][0] != s[0][0])
            for (int j = 0; j < n; j++)
                s[i][j] = 'L' + 'R' - s[i][j];
    for (int i = 1; i < n; i++)
        if (s[0][i] != s[0][0])
            for (int j = 0; j < n; j++)
                s[j][i] = 'L' + 'R' - s[j][i];
    v.clear();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (s[i][j] != s[0][0])
                v.push_back({i, j});
    if (v.empty()) {
        fout << -1 << endl;
        return 0;
    }
    if (v.size() == 1) {
        fout << v[0].first + 1 << " " << v[0].second + 1 << endl;
        return 0;
    }

    bool b1 = true;
    bool b2 = true;
    for (auto p : v) {
        b1 &= p.first == v[0].first;
        b2 &= p.second == v[0].second;
    }
    if (b1)
        fout << v[0].first + 1 << " " << 1 << endl;
    else if (b2)
        fout << 1 << " " << v[0].second + 1 << endl;
    else
        fout << -1 << endl;
}