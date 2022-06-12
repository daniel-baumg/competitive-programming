#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("guess.in");
    ofstream fout("guess.out");

    int n;
    fin >> n;
    map<string, set<string>> m;
    for (int i = 0; i < n; i++) {
        string name;
        int k;
        fin >> name >> k;
        while (k--) {
            string s;
            fin >> s;
            m[name].insert(s);
        }
    }

    int ans = 0;
    for (auto p1 : m) {
        for (auto p2 : m) {
            if (p1 == p2)
                continue;
            int temp = 0;
            for (auto s : p1.second)
                if (p2.second.count(s) == 1)
                    temp += 1;
            if (p1.second.size() > temp)
                temp += 1;
            ans = max(ans, temp);
        }
    }
    fout << ans << endl;
}