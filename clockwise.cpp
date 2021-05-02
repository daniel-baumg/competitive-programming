#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int l = 0;
        int r = 0;
        for (int j = 0; j < s.size() - 1; j++) {
            string turn = s.substr(j, 2);
            if (turn == "NW") l += 1;
            if (turn == "WS") l += 1;
            if (turn == "SE") l += 1;
            if (turn == "EN") l += 1;
            if (turn == "NE") r += 1;
            if (turn == "ES") r += 1;
            if (turn == "SW") r += 1;
            if (turn == "WN") r += 1;
        }
        if (l > r) cout << "CCW" << endl;
        if (l < r) cout << "CW" << endl;
    }
}