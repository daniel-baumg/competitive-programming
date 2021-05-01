#include <bits/stdc++.h>
using namespace std;

int moo = 0;
int arr[100001];
int fav[100000][2];

void next_choice(int cow, int type) {
    int other = arr[fav[cow][type]];
    arr[fav[cow][type]] = cow;
    if (other == arr[fav[other][1]])
        moo += 1;
    else if (arr[fav[other][1]] == -1)
        arr[fav[other][1]] = other;
    else if (arr[fav[other][1]] < other)
        moo += 1;
    else
        next_choice(other, 1);
}

int main() {
    ifstream fin("cereal.in");
    ofstream fout("cereal.out");

    int n, m;
    fin >> n >> m;
    for (int i = 0; i < n; i++)
        fin >> fav[i][0] >> fav[i][1];

    int ans[100000];
    fill_n(arr, n + 1, -1);
    for (int i = n - 1; i >= 0; i--) {
        if (arr[fav[i][0]] == -1)
            arr[fav[i][0]] = i;
        else
            next_choice(i, 0);
        ans[i] = n - i - moo;
    }
    for (int i = 0; i < n; i++)
        fout << ans[i] << endl;
}
