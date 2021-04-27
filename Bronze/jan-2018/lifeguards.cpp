#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");

    int n;
    fin >> n;
    int start[100], end[100];
    for (int i = 0; i < n; i++)
        fin >> start[i] >> end[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool covered[1000] = {};
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            for (int k = start[j]; k < end[j]; k++)
                covered[k - 1] = true;
        }
        int count = 0;
        for (int j = 0; j < 1000; j++)
            if (covered[j])
                count += 1;
        ans = max(ans, count);
    }
    fout << ans << endl;
}
