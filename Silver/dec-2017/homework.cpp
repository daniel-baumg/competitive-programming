#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("homework.in");
    ofstream fout("homework.out");

    int n;
    fin >> n;
    int scores[100000];
    for (int i = 0; i < n; i++)
        fin >> scores[i];

    double sum = scores[n - 1];
    int min_score = scores[n - 1];
    vector<double> avg;
    for (int i = n - 2; i > 0; i--) {
        sum += scores[i];
        min_score = min(min_score, scores[i]);
        avg.push_back((sum - min_score) / (n - i - 1));
    }
    double max_avg = 0;
    for (int i = 0; i < n - 2; i++)
        max_avg = max(max_avg, avg[i]);

    vector<int> ans;
    for (int i = 0; i < n - 2; i++)
        if (avg[i] == max_avg)
            ans.push_back(n - i - 2);
    sort(ans.begin(), ans.end());
    for (int i : ans)
        fout << i << endl;
}
