#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("berries.in");
    ofstream fout("berries.out");

    int n, k;
    fin >> n >> k;
    int b[n];
    for (int i = 0; i < n; i++)
        fin >> b[i];
    sort(b, b + n);

    int ans = 0;
    for (int i = 1; i <= 1000; i++) {
        priority_queue<int> pq;
        for (int j = 0; j < n; j++)
            pq.push(b[j]);
        bool valid = true;
        int t = k / 2;
        while (t--) {
            if (pq.empty()) {
                valid = false;
                break;  
            }
            auto cur = pq.top();
            pq.pop();
            if (cur < i) {
                valid = false;
                break;
            } else {
                pq.push(max(0, cur - i));
            }
        }
        if (!valid)
            continue;
        int s = 0;
        t = k / 2;
        while (t--) {
            if (!pq.empty()) {
                auto cur = pq.top();
                s += min(cur, i);
                pq.pop();
                pq.push(max(0, cur - i));
            }
        }
        ans = max(ans, s);
    }
    fout << ans << endl;
}
