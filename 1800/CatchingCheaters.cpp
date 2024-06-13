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
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;

    int ans = 0;
    v dp(n + 1, v<int>(m + 1, -1e9));
    auto go = [&](int i, int j, auto&& go) -> int {
        if (dp[i][j] != -1e9) return dp[i][j];
        if (i == n or j == m) return 0;

        dp[i][j] = max({
            go(i + 1, j, go) - 1,
            go(i, j + 1, go) - 1,
            go(i + 1, j + 1, go) - 2 + 4 * (s[i] == t[j])
        });
        dp[i][j] = max(dp[i][j], 0ll);

        ans = max(ans, dp[i][j]);
        return dp[i][j];
    };
    go(0, 0, go);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}