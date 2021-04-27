#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");

    int n;
    fin >> n;
    int x[100], y[100];
    for (int i = 0; i < n; i++)
        fin >> x[i] >> y[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (x[i] == x[j] && y[i] == y[k])
                    ans = max(ans, abs((x[i] - x[k]) * (y[i] - y[j])));
                if (x[i] == x[j] && y[j] == y[k])
                    ans = max(ans, abs((x[i] - x[k]) * (y[i] - y[j])));
                if (x[i] == x[k] && y[i] == y[j])
                    ans = max(ans, abs((x[i] - x[j]) * (y[i] - y[k])));
                if (x[i] == x[k] && y[j] == y[k])
                    ans = max(ans, abs((x[i] - x[j]) * (y[i] - y[j])));
                if (x[j] == x[k] && y[i] == y[j])
                    ans = max(ans, abs((x[i] - x[j]) * (y[i] - y[k])));
                if (x[j] == x[k] && y[i] == y[k])
                    ans = max(ans, abs((x[i] - x[j]) * (y[i] - y[j])));
            }
        }
    }

    fout << ans << endl;
}