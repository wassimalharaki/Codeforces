#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair

int32_t main() {
    fast

    string s;

    cin >> s;

    char c = 'a';
    int rots = 0;

    for (int i = 0; i < s.size(); i++) {
        rots += min(abs(c - s[i]), 26 - abs(c - s[i]));
        c = s[i];
    }

    cout << rots nl;

    return 0;
}