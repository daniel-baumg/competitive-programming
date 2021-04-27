#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("whereami.in");
    ofstream fout("whereami.out");

    int n;
    string houses;
    fin >> n >> houses;
    int k = 1;
    while (k < n) {
        for (int i = 0; i < n - k + 1; i++)
            for (int j = i + 1; j < n - k + 1; j++)
                if (houses.substr(i, k) == houses.substr(j, k))
                    goto next;
        break;
        next: k += 1;
    }
    fout << k << endl;
}