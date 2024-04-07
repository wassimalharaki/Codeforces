#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    v<v<int>> letters(26);
    for (int i = 0; i < n; i++)
        letters[s[i] - 'a'].push_back(i);

    for (char& c : t)
        if (letters[c - 'a'].empty()) {
            cout << -1 << nl;
            return;
        }

    int ops = 1, prev = -1;
    for (int i = 0; i < m; i++) {
        int j = t[i] - 'a';
        auto it = upper_bound(all(letters[j]), prev);
        if (it == letters[j].end()) {
            ops++;
            prev = letters[j][0];
        }
        else
            prev = *it;
    }
    cout << ops << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}