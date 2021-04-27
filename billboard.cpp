#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");

    int b1x1, b1y1, b1x2, b1y2, b2x1, b2y1, b2x2, b2y2;
    fin >> b1x1 >> b1y1 >> b1x2 >> b1y2 >> b2x1 >> b2y1 >> b2x2 >> b2y2;
    int x = b1x2 - b1x1;
    int y = b1y2 - b1y1;
    if (b2x1 < b1x1 && b2y1 < b1y1 && b2x2 > b1x1 && b2y2 > b1y2)
        x -= b2x2 - b1x1;
    if (b2x2 > b1x2 && b2y2 > b1y2 && b2x1 < b1x2 && b2y1 < b1y1)
        x -= b1x2 - b2x1;
    if (b2y1 < b1y1 && b2x1 < b1x1 && b2y2 > b1y1 && b2x2 > b1x2)
        y -= b2y2 - b1y1;
    if (b2y2 > b1y2 && b2x2 > b1x2 && b2y1 < b1y2 && b2x1 < b1x1)
        y -= b1y2 - b2y1;
    x = max(x, 0);
    y = max(y, 0);
    fout << x * y << endl;
}