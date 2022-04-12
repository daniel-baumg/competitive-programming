#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("race.in");
    ofstream fout("race.out");

    int k, n;
    fin >> k >> n;

    while (n--) {
        int x;
        fin >> x;
        int ans = 0;
        long long position = 0;
        long long speed = 0;
        while (position < k) {
            ans += 1;
            if (position + x * (speed + 1 - x) + (speed + 1 - x) * (speed + 2 - x) / 2 < k)
                speed += 1;
            else if (position + x * (speed - x) + (speed - x) * (speed + 1 - x) / 2 >= k)
                speed -= 1;
            position += speed;
        }
        fout << ans << endl;
    }
}