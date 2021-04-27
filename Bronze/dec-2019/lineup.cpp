#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("lineup.in");
    ofstream fout("lineup.out");

    int n;
    fin >> n;
    string conditions[7][2];
    vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    for (int i = 0; i < n; i++) {
        string x, y;
        fin >> x >> y >> y >> y >> y >> y;
        conditions[i][0] = x;
        conditions[i][1] = y;
    }

    do {
        bool valid = true;
        for (int j = 0; j < n; j++) {
            int x, y;
            for (int k = 0; k < 8; k++) {
                if (cows[k] == conditions[j][0]) x = k;
                if (cows[k] == conditions[j][1]) y = k;
            }
            if (x != y + 1 && x != y - 1)
                valid = false;
        }
        if (valid) {
            for (int j = 0; j < 8; j++)
                fout << cows[j] << endl;
            break;
        }
    } while (next_permutation(cows.begin(), cows.end()));
}
