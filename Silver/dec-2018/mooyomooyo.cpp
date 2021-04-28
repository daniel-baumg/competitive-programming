#include <bits/stdc++.h>
using namespace std;

int n;
string grid[100];

bool gravity() {
    bool changed = false;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j] != '0' && grid[i + 1][j] == '0') {
                grid[i + 1][j] = grid[i][j];
                grid[i][j] = '0';
                changed = true;
            }
        }
    }
    return changed;
}

int area(bool visited[100][10], int i, int j) {
    int a = 0;
    char c = grid[i][j];
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if (cur.first < 0 || cur.first >= n || cur.second < 0 || cur.second >= 10 || grid[cur.first][cur.second] != c)
            continue;
        if (visited[cur.first][cur.second])
            continue;
        visited[cur.first][cur.second] = true;
        a += 1;
        q.push(make_pair(cur.first + 1, cur.second));
        q.push(make_pair(cur.first - 1, cur.second));
        q.push(make_pair(cur.first, cur.second + 1));
        q.push(make_pair(cur.first, cur.second - 1));
    }
    return a;
}

void erase(int i, int j) {
    char c = grid[i][j];
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if (cur.first < 0 || cur.first >= n || cur.second < 0 || cur.second >= 10 || grid[cur.first][cur.second] != c)
            continue;
        grid[cur.first][cur.second] = '0';
        q.push(make_pair(cur.first + 1, cur.second));
        q.push(make_pair(cur.first - 1, cur.second));
        q.push(make_pair(cur.first, cur.second + 1));
        q.push(make_pair(cur.first, cur.second - 1));
    }
}

int main() {
    ifstream fin("mooyomooyo.in");
    ofstream fout("mooyomooyo.out");

    int k;
    fin >> n >> k;
    for (int i = 0; i < n; i++)
        fin >> grid[i];

    do {
        while (gravity())
            continue;
        bool visited[100][10] = {};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                if (visited[i][j] || grid[i][j] == '0')
                    continue;
                int a = area(visited, i, j);
                if (a >= k)
                    erase(i, j);
            }
        }
    } while (gravity());

    for (int i = 0; i < n; i++)
        fout << grid[i] << endl;
}
