#include <bits/stdc++.h>
using namespace std;

int area(int r[]) {
    return abs(r[3] - r[1]) * abs(r[2] - r[0]);
}

int intersection(int r1[], int r2[]) {
    int x1 = max(r1[0], r2[0]);
    int y1 = max(r1[1], r2[1]);
    int x2 = min(r1[2], r2[2]);
    int y2 = min(r1[3], r2[3]);
    int temp[4] = {x1, y1, x2, y2};
    if (x1 < x2 && y1 < y2)
        return area(temp);
    return 0;
}

int main() {
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");

    int b1[4], b2[4], t[4];
    fin >> b1[0] >> b1[1] >> b1[2] >> b1[3] >> b2[0] >> b2[1] >> b2[2] >> b2[3] >> t[0] >> t[1] >> t[2] >> t[3];
    fout << area(b1) + area(b2) - intersection(b1, t) - intersection(b2, t) << endl;
}