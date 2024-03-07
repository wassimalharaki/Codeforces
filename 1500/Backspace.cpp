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

    auto f = [](int i, int j) {
        return (i & 1) != (j & 1);
    };

    auto check = [&](int i) {
        int j = 1, prev = i++;
        while (i < n and j < m) {
            if (s[i] == t[j] and f(i, prev)) {
                prev = i;
                j++;
            }
            i++;
        }
        return j == m and ((n - prev) & 1);
    };

    array<bool, 2> par{0, 0};
    for (int i = 0; i < n; i++)
        if (s[i] == t[0] and not par[i & 1]) {
            if (check(i)) {
                cout << "YES" << nl;
                return;
            }
            par[i & 1] = 1;
        }
    cout << "NO" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}