#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("word.in");
    ofstream fout("word.out");

    int n, k;
    fin >> n >> k;
    string words[100];
    for (int i = 0; i < n; i++)
        fin >> words[i];
    int len = 0;
    string line = "";
    for (int i = 0; i < n; i++) {
        if (len + words[i].length() <= k) {
            line += words[i] + " ";
            len += words[i].length();
        } else {
            fout << line.substr(0, line.length() - 1) << endl;
            line = words[i] + " ";
            len = words[i].length();
        }
    }
    fout << line.substr(0, line.length() - 1) << endl;
}
