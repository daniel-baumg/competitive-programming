#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");

    int n;
    fin >> n;
    int a[100], mapping[100], order[100];
    for (int i = 0; i < n; i++)
        fin >> a[i];
    for (int i = 0; i < n; i++)
        fin >> order[i];
    for (int i = 0; i < n; i++)
        mapping[a[i] - 1] = i;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mapping[mapping[mapping[j]]] == i)
                fout << order[j] << endl;
}