#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    int ans = 0, curr = 0, x = 0;
    for (int i = 0; i < m; i++) {
        if (i and s[i] != s[i - 1])
            x++;
        if (s[i] != t[i])
            curr++;
    }
    ans += curr & 1 ^ 1;

    for (int i = m; i < n; i++) {
        if (s[i] != s[i - 1])
            x++;
        curr += x;
        ans += curr & 1 ^ 1;
        if (s[i - m + 1] != s[i - m])
            x--;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}