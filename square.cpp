#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("square.in");
    ofstream fout("square.out");

    int p1x1, p1y1, p1x2, p1y2, p2x1, p2y1, p2x2, p2y2;
    fin >> p1x1 >> p1y1 >> p1x2 >> p1y2 >> p2x1 >> p2y1 >> p2x2 >> p2y2;
    int x1 = min(p1x1, p2x1);
    int x2 = max(p1x2, p2x2);
    int y1 = min(p1y1, p2y1);
    int y2 = max(p1y2, p2y2);
    int side = max(x2 - x1, y2 - y1);

    fout << side * side << endl;
}