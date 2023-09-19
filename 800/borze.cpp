#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>

int32_t main() {
    fast

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            cout << 0;
        }
        else if (s[i] == '-' && s[i + 1] == '.') {
            cout << 1;
            i++;
        }
        else {
            cout << 2;
            i++;
        }
    }

    return 0;
}