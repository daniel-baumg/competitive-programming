#include <bits/stdc++.h>
using namespace std;

int main() {
    string cowphabet, word;
    cin >> cowphabet >> word;
    int ans = 0;
    for (int i = 0; i < word.length();) {
        for (int j = 0; j < 26; j++) {
            if (i == word.length())
                break;
            if (cowphabet[j] == word[i])
                i++;
        }
        ans += 1;
    }
    cout << ans << endl;
}