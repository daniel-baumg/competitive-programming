#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("traffic.in");
    ofstream fout("traffic.out");

    int n;
    fin >> n;
    vector<tuple<bool, bool, bool, int, int>> traffic;
    for (int i = 0; i < n; i++) {
        string type;
        int a, b;
        fin >> type >> a >> b;
        traffic.push_back(make_tuple(type[1] == 'n', type[1] == 'f', type[1] == 'o', a, b));
    }

    int idx1, idx2, lo, hi;
    for (int i = 0; i < n; i++)
        if (get<2>(traffic[i]))
            idx1 = i;
    for (int i = 0; i < n; i++) {
        if (get<2>(traffic[i])) {
            idx2 = i;
            break;
        }
    }

    lo = get<3>(traffic[idx1]);
    hi = get<4>(traffic[idx1]);
    for (int i = idx1 - 1; i >= 0; i--) {
        if (get<0>(traffic[i])) {
            lo -= get<4>(traffic[i]);
            hi -= get<3>(traffic[i]);
        } else if (get<1>(traffic[i])) {
            lo += get<3>(traffic[i]);
            hi += get<4>(traffic[i]);
        } else {
            lo = max(lo, get<3>(traffic[i]));
            hi = min(hi, get<4>(traffic[i]));
        }
    }
    lo = max(lo, 0);
    fout << lo << " " << hi << endl;

    lo = get<3>(traffic[idx2]);
    hi = get<4>(traffic[idx2]);
    for (int i = idx2 + 1; i < n; i++) {
        if (get<0>(traffic[i])) {
            lo += get<3>(traffic[i]);
            hi += get<4>(traffic[i]);
        } else if (get<1>(traffic[i])) {
            lo -= get<4>(traffic[i]);
            hi -= get<3>(traffic[i]);
        } else {
            lo = max(lo, get<3>(traffic[i]));
            hi = min(hi, get<4>(traffic[i]));
        }
    }
    lo = max(lo, 0);
    fout << lo << " " << hi << endl;
}
