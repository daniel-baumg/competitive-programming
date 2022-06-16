#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("evolution.in");
    ofstream fout("evolution.out");

    int n;
    fin >> n;
    map<string, set<int>> cows;
    for (int i = 0; i < n; i++) {
        int k;
        fin >> k;
        while (k--) {
            string s;
            fin >> s;
            cows[s].insert(i);
        }
    }

    bool ans = true;
    for (auto p1 : cows) {
        for (auto p2 : cows) {
            if (p1 == p2)
                continue;
            bool b1 = false;
            bool b2 = false;
            bool b3 = false;
            for (int cow : p1.second) b1 |= p2.second.count(cow) == 0;
            for (int cow : p2.second) b2 |= p1.second.count(cow) == 0;
            for (int cow : p2.second) b3 |= p1.second.count(cow) == 1;
            ans &= !(b1 && b2 && b3);
        }
    }
    if (ans)
        fout << "yes" << endl;
    else
        fout << "no" << endl;
}