#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("cbarn.in");
    ofstream fout("cbarn.out");

    int n;
    fin >> n;
    int c[1000];
    for (int i = 0; i < n; i++)
        fin >> c[i];
    vector<multiset<int>> rooms;
    for (int i = 0; i < n; i++) {
        multiset<int> room;
        for (int j = 0; j < c[i]; j++)
            room.insert(0);
        rooms.push_back(room);
    }

    int ans = 0;
    bool done = false;
    while (!done) {
        done = true;
        for (int i = 0; i < n; i++) {
            while (rooms[i].size() > 1) {
                done = false;
                int cur = *rooms[i].begin();
                rooms[i].erase(rooms[i].begin());
                ans -= cur * cur;
                cur += 1;
                ans += cur * cur;
                rooms[(i + 1) % n].insert(cur);
            }
        }
    }
    fout << ans << endl;
}
