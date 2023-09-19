#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string username;
    string distinct;
    cin >> username;

    loop(i, 0, username.length()) {
        char c = username[i];
        if (((int) distinct.find(c)) == - 1)
            distinct += c;
    }
    if (distinct.length() % 2 == 1)
        cout << "IGNORE HIM!";
    else
        cout << "CHAT WITH HER!";

    return 0;
}