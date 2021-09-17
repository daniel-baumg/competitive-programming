#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("blocks.in");
    ofstream fout("blocks.out");

    int n;
    fin >> n;
    int ans[26] = {};
    for (int i = 0; i < n; i++) {
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        int blocks1[26] = {};
        int blocks2[26] = {};
        string word1, word2;
        fin >> word1 >> word2;
        for (int j = 0; j < word1.length(); j++) blocks1[alphabet.find(word1[j])] += 1;
        for (int j = 0; j < word2.length(); j++) blocks2[alphabet.find(word2[j])] += 1;
        for (int j = 0; j < 26; j++)
            ans[j] += max(blocks1[j], blocks2[j]);
    }

    for (int i = 0; i < 26; i++)
        fout << ans[i] << endl;
}
