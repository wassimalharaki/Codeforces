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

using ai2 = array<int, 2>;

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> a(n, v<int>(m));
    for (auto& x : a)
        for (int& y : x)
            cin >> y;
    
    v<v<ai2>> dp(n + 1, v<ai2>(m + 1, {(int) 1e9, (int) -1e9}));
    dp[1][1] = {a[0][0], a[0][0]};
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (i == 1 and j == 1) continue;
            int x = a[i - 1][j - 1];
            dp[i][j][0] = min(dp[i - 1][j][0] + x, dp[i][j - 1][0] + x);
            dp[i][j][1] = max(dp[i - 1][j][1] + x, dp[i][j - 1][1] + x);
        }

    bool ans = dp[n][m][0] <= 0 and dp[n][m][1] >= 0 and (dp[n][m][0] & 1 ^ 1);
    cout << (ans ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}