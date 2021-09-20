#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("cowqueue.in");
    ofstream fout("cowqueue.out");

    int n;
    fin >> n;
    vector<pair<int,int>> cows;
    for (int i = 0; i < n; i++) {
        int arrival, duration;
        fin >> arrival >> duration;
        cows.push_back(make_pair(arrival, duration));
    }
    sort(cows.begin(), cows.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, cows[i].first);
        ans += cows[i].second;
    }
    fout << ans << endl;
}
