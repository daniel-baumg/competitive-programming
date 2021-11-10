#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("tracing.in");
    ofstream fout("tracing.out");

    int n, t;
    string s;
    fin >> n >> t >> s;
    vector<tuple<int, int, int>> log;
    for (int i = 0; i < t; i++) {
        int time, x, y;
        fin >> time >> x >> y;
        log.push_back(make_tuple(time, x - 1, y - 1));
    }
    sort(log.begin(), log.end());

    int lo = 250;
    int hi = 0;
    set<int> zero;
    for (int k = 250; k >= 0; k--) {
        for (int i = 0; i < n; i++) {
            bool sick[100] = {};
            int shakes[100] = {};
            sick[i] = true;
            shakes[i] = k;
            for (auto entry : log) {
                int x = get<1>(entry);
                int y = get<2>(entry);
                if (shakes[x] > 0 && shakes[y] > 0) {
                    shakes[x] -= 1;
                    shakes[y] -= 1;
                } else if (shakes[x] > 0 && sick[y]) {
                    shakes[x] -= 1;
                } else if (shakes[y] > 0 && sick[x]) {
                    shakes[y] -= 1;
                } else if (shakes[x] > 0) {
                    shakes[x] -= 1;
                    shakes[y] = k;
                    sick[y] = true;
                } else if (shakes[y] > 0) {
                    shakes[y] -= 1;
                    shakes[x] = k;
                    sick[x] = true;
                }
            }
            bool valid = true;
            for (int j = 0; j < n; j++)
                valid &= (s[j] == '1') == sick[j];
            if (valid) {
                zero.insert(i);
                lo = min(lo, k);
                hi = max(hi, k);
            }
        }
    }
    fout << zero.size() << " " << lo << " ";
    if (hi == 250) {
        fout << "Infinity" << endl;
    } else {
        fout << hi << endl;
    }
}
