#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("photo.in");
    ofstream fout("photo.out");

    int n;
    fin >> n;
    int b[1000];
    for (int i = 0; i < n - 1; i++)
        fin >> b[i];

    for (int i = 0; i < n; i++) {
        int a[1000];
        a[0] = i + 1;
        for (int j = 1; j < n; j++)
            a[j] = b[j - 1] - a[j - 1];
        bool exists[1000] = {};
        for (int j = 0; j < n; j++)
            if (0 < a[j] && a[j] < 1001)
                exists[a[j] - 1] = true;
        bool valid = true;
        for (int j = 0; j < n; j++)
            valid &= exists[j];
        if (valid) {
            for (int j = 0; j < n - 1; j++)
                fout << a[j] << " ";
            fout << a[n - 1] << endl;
            break;
        }
    }
}