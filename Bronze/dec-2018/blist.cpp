#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("blist.in");
    ofstream fout("blist.out");

    int n;
    fin >> n;
    int s[100], t[100], b[100], times[200];
    for (int i = 0; i < n; i++) {
        fin >> s[i] >> t[i] >> b[i];
        times[2 * i] = s[i];
        times[2 * i + 1] = t[i];
    }

    sort(times, times + 2 * n);
    int active = 0;
    int ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        bool start = true;
        int idx = -1;
        for (int j = 0; j < n; j++)
            if (s[j] == times[i])
                idx = j;
        if (idx == -1) {
            start = false;
            for (int j = 0; j < n; j++)
                if (t[j] == times[i])
                    idx = j;
        }
        if (start)
            active += b[idx];
        else
            active -= b[idx];
        ans = max(ans, active);
    }
    fout << ans << endl;
}
