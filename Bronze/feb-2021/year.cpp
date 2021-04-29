#include <bits/stdc++.h>
using namespace std;

int convert(string s) {
    string zodiac[12] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
    for (int i = 0; i < 12; i++)
        if (s == zodiac[i])
            return i;
    return -1;
}

int next(string s, int year) {
    int val = convert(s);
    year += 1;
    while (year % 12 != val)
        year += 1;
    return year;
}

int prev(string s, int year) {
    int val = convert(s);
    year -= 1;
    while (year % 12 != val)
        year -= 1;
    return year;
}

int main() {
    int n;
    cin >> n;
    map<string, int> m;
    m["Bessie"] = 1200;
    for (int i = 0; i < n; i++) {
        string cow1, cow2, type, animal;
        cin >> cow1 >> type >> type >> type >> animal >> cow2 >> cow2 >> cow2;
        if (type == "previous")
            m[cow1] = prev(animal, m[cow2]);
        else
            m[cow1] = next(animal, m[cow2]);
    }
    cout << abs(m["Bessie"] - m["Elsie"]) << endl;
}
