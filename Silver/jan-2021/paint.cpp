#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    string s;
    cin >> n >> q >> s;

    int prefix[n + 1] = {};
    prefix[1] = 1;
    set<char> visited;
    visited.insert(s[0]);
    for (int i = 1; i < n; i++) {
        prefix[i + 1] = prefix[i];
        if (s[i - 1] < s[i] || visited.count(s[i]) == 0)
            prefix[i + 1] += 1;
        visited.insert(s[i]);
        for (char c : "ABCDEFGHIJKLMNOPQRSTUVWXYZ")
            if (c > s[i])
                visited.erase(c);
    }

    int suffix[n + 1] = {};
    suffix[n - 1] = 1;
    visited.clear();
    visited.insert(s[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1];
        if (s[i] > s[i + 1] || visited.count(s[i]) == 0)
            suffix[i] += 1;
        visited.insert(s[i]);
        for (char c : "ABCDEFGHIJKLMNOPQRSTUVWXYZ")
            if (c > s[i])
                visited.erase(c);
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << prefix[a - 1] + suffix[b] << endl;
    }
}