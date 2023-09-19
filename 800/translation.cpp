#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    string t;

    cin >> s >> t;
    if (s.length() != t.length()) {
        cout << "NO";
        return 0;
    }

    loop(i, 0, s.length()) {
        if (s[i] != t[t.length() - 1 - i]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}