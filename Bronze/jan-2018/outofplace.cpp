#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("outofplace.in");
    ofstream fout("outofplace.out");

    int n;
    fin >> n;
    int line[100], cows[100];
    for (int i = 0; i < n; i++) {
        fin >> line[i];
        cows[i] = line[i];
    }
    sort(cows, cows + n);

    int x = 0;
    int y = n - 1;
    while (line[x] == cows[x]) x += 1;
    while (line[y] == cows[y]) y -= 1;
    set<int> s;
    for (int i = x; i < y + 1; i++)
        s.insert(line[i]);
    fout << s.size() - 1 << endl;
}