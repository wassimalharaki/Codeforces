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
    int n, m, o; cin >> n >> m >> o;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<v<int>> c(n, v<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
            c[i][j] = (a[i] ? (a[i] - 1 == j ? 0 : 1e15) : c[i][j]);
        }
    
    v dp = v(n + 1, v(m + 1, v<int>(o + 1, 1e15)));
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 0; k <= o; k++)
                for (int l = 0; l <= m; l++)
                    if (k + (j != l) <= o)
                        dp[i][j][k + (j != l)] = min(
                            dp[i][j][k + (j != l)],
                            c[i - 1][j - 1] + dp[i - 1][l][k]
                        );

    int ans = 1e18;
    for (int i = 1; i <= m; i++)
        ans = min(ans, dp[n][i][o]);
    cout << (ans >= 1e15 ? -1 : ans);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}