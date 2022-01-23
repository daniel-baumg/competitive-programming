#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("helpcross.in");
    ofstream fout("helpcross.out");

    int c, n;
    fin >> c >> n;
    set<int> times;
    map<int, int> chickens;
    for (int i = 0; i < c; i++) {
        int t;
        fin >> t;
        chickens[t] += 1;
        times.insert(t);
    }
    map<int, vector<int>> cows;
    for (int i = 0; i < n; i++) {
        int a, b;
        fin >> a >> b;
        cows[a].push_back(b + 1);
        times.insert(a);
        times.insert(b + 1);
    }

    int ans = 0;
    multiset<int> active;
    for (auto t : times) {
        active.erase(t);
        for (auto cow : cows[t])
            active.insert(cow);
        while (chickens[t] > 0 && active.size() > 0) {
            ans += 1;
            chickens[t] -= 1;
            active.erase(active.begin());
        }
    }
    fout << ans << endl;
}
