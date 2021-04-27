#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("teleport.in");
    ofstream fout("teleport.out");

    int a, b, x, y;
    fin >> a >> b >> x >> y;
    fout << min(min(abs(a - x) + abs(b - y), abs(a - y) + abs(b - x)), abs(a - b)) << endl;
}
