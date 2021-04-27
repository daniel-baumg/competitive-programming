#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("measurement.in");
    ofstream fout("measurement.out");

    int n;
    fin >> n;
    vector<tuple<int, string, int>> log;
    for (int i = 0; i < n; i++) {
        int day, change;
        string cow;
        fin >> day >> cow >> change;
        log.push_back(make_tuple(day, cow, change));
    }
    sort(log.begin(), log.end());

    int ans = 0;
    map<string, int> milk;
    milk["Bessie"] = 7;
    milk["Elsie"] = 7;
    milk["Mildred"] = 7;
    set<string> display;
    display.insert("Bessie");
    display.insert("Elsie");
    display.insert("Mildred");
    for (int i = 0; i < n; i++) {
        milk[get<1>(log[i])] += get<2>(log[i]);
        int max_milk = max(max(milk["Bessie"], milk["Elsie"]), milk["Mildred"]);
        set<string> updated_display;
        if (milk["Bessie"] == max_milk)
            updated_display.insert("Bessie");
        if (milk["Elsie"] == max_milk)
            updated_display.insert("Elsie");
        if (milk["Mildred"] == max_milk)
            updated_display.insert("Mildred");
        if (display != updated_display)
            ans += 1;
        display = updated_display;
    }
    fout << ans << endl;
}
