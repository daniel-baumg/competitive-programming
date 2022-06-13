#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("trapped.in");
    ofstream fout("trapped.out");

    int n;
    fin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) {
        int x, y;
        fin >> x >> y;
        a[i] = {y, x};
    }
    sort(a, a + n);

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        queue<pair<int, int>> q1, q2;
        for (int j = i; j >= 0; j--)
            q1.push(a[j]);
        for (int j = i + 1; j < n; j++)
            q2.push(a[j]);
        while (!q1.empty() && !q2.empty()) {
            int d = q2.front().first - q1.front().first;
            if (q1.front().second < d)
                q1.pop();
            else if (q2.front().second < d)
                q2.pop();
            else
                break;
        }
        if (!q1.empty() && !q2.empty())
            ans += a[i + 1].first - a[i].first;
    }
    fout << ans << endl;
}