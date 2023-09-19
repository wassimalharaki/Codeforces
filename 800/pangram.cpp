#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    char c;
    vector<bool> letters(26, false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c;
        letters[tolower(c) - 'a'] = true;
    }

    for (int i = 0; i < 26; i++)
        if (not letters[i]) {
            cout << "NO";
            return 0;
        }

    cout << "YES";
    return 0;
}