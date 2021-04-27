#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("lemonade.in");
    ofstream fout("lemonade.out");

    int n;
    fin >> n;
    vector<int> cows;
    for (int i = 0; i < n; i++) {
        int w;
        fin >> w;
        cows.push_back(w);
    }
    sort(cows.rbegin(), cows.rend());
    vector<int> line;
    for (int i = 0; i < n; i++)
        if (line.size() <= cows[i])
            line.push_back(cows[i]);
    fout << line.size() << endl;
}
