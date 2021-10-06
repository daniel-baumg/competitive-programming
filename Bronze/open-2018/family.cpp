#include <bits/stdc++.h>
using namespace std;

int id[202];
set<string> cows;

int find(int v) {
    if (v == id[v])
        return v;
    return id[v] = find(id[v]);
}

void merge(int u, int v) {
    int a = find(u);
    int b = find(v);
    id[a] = b;
}

int convert(string s) {
    int idx = 0;
    for (string cow : cows) {
        if (s == cow)
            return idx;
        idx += 1;
    }
    return -1;
}

int main() {
    ifstream fin("family.in");
    ofstream fout("family.out");

    int n;
    string a, b;
    fin >> n >> a >> b;
    cows.insert(a);
    cows.insert(b);
    map<string, set<string>> children;
    map<string, string> parent;
    for (int i = 0; i < n; i++) {
        string x, y;
        fin >> x >> y;
        cows.insert(x);
        cows.insert(y);
        children[x].insert(y);
        parent[y] = x;
    }

    map<string, vector<string>> ancestors;
    for (string cow : cows) {
        string s = cow;
        while (parent.count(s) > 0) {
            s = parent[s];
            ancestors[cow].push_back(s);
        }
    }
    for (int i = 0; i < 202; i++)
        id[i] = i;
    for (auto p : parent)
        merge(convert(p.first), convert(p.second));

    string ans = "";
    if (find(convert(a)) == find(convert(b))) {
        if (parent[a] == parent[b]) {
            ans = "SIBLINGS";
            goto done;
        }
        if (parent[a] == b) {
            ans += b;
            ans += " is the mother of ";
            ans += a;
            goto done;
        }
        if (parent[b] == a) {
            ans += a;
            ans += " is the mother of ";
            ans += b;
            goto done;
        }
        for (int i = 0; i < ancestors[a].size(); i++) {
            if (ancestors[a][i] == b) {
                ans += b;
                ans += " is the ";
                for (int j = 0; j < i - 1; j++)
                    ans += "great-";
                ans += "grand-mother of ";
                ans += a;
                goto done;
            }
        }
        for (int i = 0; i < ancestors[b].size(); i++) {
            if (ancestors[b][i] == a) {
                ans += a;
                ans += " is the ";
                for (int j = 0; j < i - 1; j++)
                    ans += "great-";
                ans += "grand-mother of ";
                ans += b;
                goto done;
            }
        }
        for (int i = 0; i < ancestors[a].size(); i++) {
            if (children[ancestors[a][i]].count(b) == 1) {
                ans += b;
                ans += " is the ";
                for (int j = 0; j < i - 1; j++)
                    ans += "great-";
                ans += "aunt of ";
                ans += a;
                goto done;
            }
        }
        for (int i = 0; i < ancestors[b].size(); i++) {
            if (children[ancestors[b][i]].count(a) == 1) {
                ans += a;
                ans += " is the ";
                for (int j = 0; j < i - 1; j++)
                    ans += "great-";
                ans += "aunt of ";
                ans += b;
                goto done;
            }
        }
        ans = "COUSINS";
    } else {
        ans = "NOT RELATED";
    }
    done: fout << ans << endl;
}