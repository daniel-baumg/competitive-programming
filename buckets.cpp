#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("buckets.in");
    ofstream fout("buckets.out");

    string farm[10];
    for (int i = 0; i < 10; i++)
        fin >> farm[i];
    int bx, by, lx, ly, rx, ry;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (farm[i][j] == 'B') {
                bx = i;
                by = j;
            }
            if (farm[i][j] == 'R') {
                rx = i;
                ry = j;
            }
            if (farm[i][j] == 'L') {
                lx = i;
                ly = j;
            }
        }
    }

    bool collinear = false;
    if (lx == rx && rx == bx)
        if ((ly < ry && ry < by) || (ly > ry && ry > by))
            collinear = true;
    if (ly == ry && ry == by)
        if ((lx < rx && rx < bx) || (lx > rx && rx > bx))
            collinear = true;
    if (collinear)
        fout << max(abs(lx - bx), abs(ly - by)) + 1 << endl;
    else
        fout << abs(lx - bx) + abs(ly - by) - 1 << endl;
}