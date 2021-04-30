#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("badmilk.in");
    ofstream fout("badmilk.out");

    int n, m, d, s;
    fin >> n >> m >> d >> s;
    int transcript[1000][3];
    set<int> drank[51];
    for (int i = 0; i < d; i++) {
        fin >> transcript[i][0] >> transcript[i][1] >> transcript[i][2];
        drank[transcript[i][1]].insert(transcript[i][0]);
    }
    map<int, int> sick_times;
    set<int> sick;
    for (int i = 0; i < s; i++) {
        int p, t;
        fin >> p >> t;
        sick_times[p] = t;
        sick.insert(p);
    }

    set<int> bad_milk;
    for (int milk = 1; milk < m + 1; milk++) {
        bool possible = true;
        for (int p : sick) {
            if (drank[milk].count(p) == 0) {
                possible = false;
            } else {
                int time = INT_MAX;
                for (int i = 0; i < d; i++)
                    if (transcript[i][0] == p && transcript[i][1] == milk)
                        time = min(time, transcript[i][2]);
                possible &= time < sick_times[p];
            }
        }
        if (possible)
            bad_milk.insert(milk);
    }

    int ans = 0;
    for (int milk : bad_milk)
        if (includes(drank[milk].begin(), drank[milk].end(), sick.begin(), sick.end()))
            ans = max(ans, (int) drank[milk].size());
    fout << ans << endl;
}
