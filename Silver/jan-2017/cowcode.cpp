#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("cowcode.in");
    ofstream fout("cowcode.out");

    string s;
    long long n;
    fin >> s >> n;

    vector<long long> idx;
    long long k = s.size() + 1;
    while (k < n) {
        idx.push_back(k);
        k -= 1;
        k *= 2;
        k += 1;
    }

    long long ans = n;
    while (ans > s.size()) {
        long long cur = idx[upper_bound(idx.begin(), idx.end(), ans) - idx.begin() - 1];
        if (ans == cur)
            ans -= 1;
        else
            ans -= cur;
    }
    fout << s[ans - 1] << endl;
}
