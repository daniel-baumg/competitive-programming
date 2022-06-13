#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("convention2.in");
    ofstream fout("convention2.out");

    int n;
    fin >> n;
    int a[100000], t[100000];
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        fin >> a[i] >> t[i];
        pq.push({-a[i], i});
    }

    int time = 0;
    int eat[100000];
    priority_queue<int> waiting;
    while (!pq.empty()) {
        time = max(time, -pq.top().first);
        update:
            while (!pq.empty() && time >= -pq.top().first) {
                waiting.push(-pq.top().second);
                pq.pop();
            }
        while (!waiting.empty()) {
            int cur = -waiting.top();
            waiting.pop();
            eat[cur] = time;
            time += t[cur];
            goto update;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, eat[i] - a[i]);
    fout << ans << endl;
}
