#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("angry.in");
    ofstream fout("angry.out");

    int n;
    fin >> n;
    int x[100];
    for (int i = 0; i < n; i++)
        fin >> x[i];
    sort(x, x + n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        bool visited[100] = {};
        visited[i] = true;
        queue<pair<int, int>> q;
        q.push(make_pair(x[i], 1));
        while (!q.empty()) {
            int cow = q.front().first;
            int radius = q.front().second;
            q.pop();
            count += 1;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && cow - radius <= x[j] && x[j] <= cow + radius) {
                    q.push(make_pair(x[j], radius + 1));
                    visited[j] = true;
                }
            }
        }
        ans = max(ans, count);
    }
    fout << ans << endl;
}
