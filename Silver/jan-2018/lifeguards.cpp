#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");

    int n;
    fin >> n;
    set<int> times;
    map<int, vector<int>> starting, ending;
    for (int i = 0; i < n; i++) {
        int t1, t2;
        fin >> t1 >> t2;
        times.insert(t1);
        times.insert(t2);
        starting[t1].push_back(i);
        ending[t2].push_back(i);
    }

    int time = 0;
    int covered = 0;
    set<int> active;
    map<int, int> m;
    for (int t : times) {
        if (active.size() > 0)
            covered += t - time;
        if (active.size() == 1)
            m[*active.begin()] += t - time;
        for (int i : starting[t])
            active.insert(i);
        for (int i : ending[t])
            active.erase(i);
        time = t;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, covered - m[i]);
    fout << ans << endl;
}