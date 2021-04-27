#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("notlast.in");
    ofstream fout("notlast.out");

    int n;
    fin >> n;
    map<string, int> mapping;
    mapping["Bessie"] = 0;
    mapping["Elsie"] = 0;
    mapping["Daisy"] = 0;
    mapping["Gertie"] = 0;
    mapping["Annabelle"] = 0;
    mapping["Maggie"] = 0;
    mapping["Henrietta"] = 0;
    for (int i = 0; i < n; i++) {
        string cow;
        int milk;
        fin >> cow >> milk;
        mapping[cow] += milk;
    }

    int m = INT_MAX;
    for (pair<string, int> x : mapping)
        m = min(m, x.second);
    int min2 = INT_MAX;
        for (pair<string, int> x : mapping)
            if (x.second > m)
                min2 = min(min2, x.second);
    int count = 0;
    for (pair<string, int> x : mapping)
        if (x.second == min2)
            count += 1;

    if (count > 1 || count == 0)
        fout << "Tie" << endl;
    else
        for (pair<string, int> x : mapping)
            if (x.second == min2)
                fout << x.first << endl;
}
