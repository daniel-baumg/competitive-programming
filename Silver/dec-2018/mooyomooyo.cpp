#include <bits/stdc++.h>
using namespace std;

bool gravity(string grid[], int n) {
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

int area(string grid[], bool visited[100][10], int i, int j, int n) {
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

void erase(string grid[], int i, int j, int n) {
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

    int n, k;
    fin >> n >> k;
    string grid[100];
    for (int i = 0; i < n; i++)
        fin >> grid[i];

    do {
        while (gravity(grid, n))
            continue;
        bool visited[100][10] = {};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                if (visited[i][j] || grid[i][j] == '0')
                    continue;
                int a = area(grid, visited, i, j, n);
                if (a >= k)
                    erase(grid, i, j, n);
            }
        }
    } while (gravity(grid, n));

    for (int i = 0; i < n; i++)
        fout << grid[i] << endl;
}
