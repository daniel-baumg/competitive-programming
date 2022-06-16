#include <bits/stdc++.h>
using namespace std;

int a[100];
vector<int> recipes[100];

bool combine(int n) {
    if (recipes[n].size() == 0)
        return false;
    bool possible = true;
    for (int i : recipes[n])
        if (a[i] == 0)
            possible &= combine(i);
    if (!possible)
        return false;
    a[n] += 1;
    for (int i : recipes[n])
        a[i] -= 1;
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cin >> k;
    while (k--) {
        int l, m;
        cin >> l >> m;
        while (m--) {
            int i;
            cin >> i;
            recipes[l - 1].push_back(i - 1);
        }
    }
    for (int i = 0; i < n; i++)
        sort(recipes[i].rbegin(), recipes[i].rend());

    while (combine(n - 1))
        continue;
    cout << a[n - 1] << endl;
}