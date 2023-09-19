#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    vector<bool> letters(26, false);

    getline(cin, s);

    int counter = 0;

    if (s.size() == 2) {
        cout << counter;
        return 0;
    }
    for (int i = 1; i < s.size();  i += 3)
        if (not letters[s[i] - 'a']) {
            letters[s[i] - 'a'] = true;
            counter++;
        }

    cout << counter;

    return 0;
}