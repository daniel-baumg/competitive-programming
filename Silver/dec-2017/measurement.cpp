#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("measurement.in");
    ofstream fout("measurement.out");

    int n, g;
    fin >> n >> g;
    map<int, int> m;
    set<int> s;
    m[0] = g;
    s.insert(0);
    vector<tuple<int, int, int>> measurements;
    for (int i = 0; i < n; i++) {
        int day, id, change;
        fin >> day >> id >> change;
        measurements.push_back(make_tuple(day, id, change));
        m[id] = g;
        s.insert(id);
    }

    int max_milk = g;
    int ans = 0;
    sort(measurements.begin(), measurements.end());
    for (int i = 0; i < n; i++) {
        int id = get<1>(measurements[i]);
        int change = get<2>(measurements[i]);
        if (change > 0) {
            if (m[id] + change > max_milk) {
                if (s.size() > 1 || m[id] != max_milk)
                    ans += 1;
                max_milk = m[id] + change;
                s.clear();
                s.insert(id);
            } else if (m[id] + change == max_milk) {
                s.insert(id);
                ans += 1;
            }
        } else if (m[id] == max_milk) {
            if (s.size() == 1) {
                m[id] += change;
                max_milk = 0;
                for (auto x : m)
                    max_milk = max(max_milk, x.second);
                s.clear();
                for (auto x : m)
                    if (x.second == max_milk)
                        s.insert(x.first);
                if (s.size() > 1 || *s.begin() != id)
                    ans += 1;
                m[id] -= change;
            } else {
                s.erase(id);
                ans += 1;
            }
        }
        m[id] += change;
    }
    fout << ans << endl;
}
