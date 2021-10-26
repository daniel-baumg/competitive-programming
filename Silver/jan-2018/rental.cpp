#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("rental.in");
    ofstream fout("rental.out");

    int n, m, r;
    fin >> n >> m >> r;
    int c[100000], rent[100000];
    for (int i = 0; i < n; i++)
        fin >> c[i];
    sort(c, c + n);

    vector<pair<int, int>> buy;
    for (int i = 0; i < m; i++) {
        int p, q;
        fin >> p >> q;
        buy.push_back(make_pair(q, p));
    }
    sort(buy.begin(), buy.end());

    priority_queue<int> pq;
    for (int i = 0; i < r; i++) {
        int rent;
        fin >> rent;
        pq.push(rent);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (pq.empty() && buy.empty())
            break;
        int milk = c[i];
        int cur = buy.size() - 1;
        long long cents = 0;
        while (milk > 0 && cur > -1) {
            int change = min(milk, buy[cur].second);
            milk -= change;
            cents += change * buy[cur].first;
            cur -= 1;
        }
        if (pq.empty() || pq.top() < cents) {
            milk = c[n - 1];
            cur = buy.size() - 1;
            cents = 0;
            while (milk > 0 && cur > -1) {
                int change = min(milk, buy[cur].second);
                milk -= change;
                cents += change * buy[cur].first;
                buy[cur].second -= change;
                if (buy[cur].second == 0)
                    buy.erase(buy.end());
                cur -= 1;
            }
            ans += cents;
            i -= 1;
            n -= 1;
        } else {
            ans += pq.top();
            pq.pop();
        }
    }
    fout << ans << endl;
}
