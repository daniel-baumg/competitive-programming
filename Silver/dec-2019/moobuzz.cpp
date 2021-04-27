#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("moobuzz.in");
    ofstream fout("moobuzz.out");

    int n;
    fin >> n;
    n -= 1;
    int vals[] = { 1, 2, 4, 7, 8, 11, 13, 14 };
    fout << (vals[n % 8] + n / 8 * 15) << endl;
}
