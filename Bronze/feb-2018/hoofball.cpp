#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("hoofball.in");
    ofstream fout("hoofball.out");

    int n;
    fin >> n;
    int x[1000];
    for (int i = 0; i < n; i++)
        fin >> x[i];
    sort(x, x + n);

    int adj[100];
    adj[0] = 1;
    adj[n - 1] = n - 2;
    for (int i = 1; i < n - 1; i++) {
        if (x[i + 1] - x[i] < x[i] - x[i - 1])
            adj[i] = i + 1;
        else
            adj[i] = i - 1;
    }
    int to[100] = {};
    for (int i = 0; i < n; i++)
        to[adj[i]] += 1;

    double ans = 0;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (to[i] == 0) {
            q.push(i);
            ans += 1;
        }
    }
    bool visited[100] = {};
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < 100; i++) {
            visited[cur] = true;
            cur = adj[cur];
        }
    }
    for (int i = 0; i < n; i++)
        if (!visited[i])
            ans += 0.5;
    fout << ans << endl;
}
