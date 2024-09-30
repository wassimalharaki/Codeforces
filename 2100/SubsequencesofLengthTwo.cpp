#include <bits/stdc++.h>
using namespace std;
// #define int long long
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

    if (t[0] == t[1]) {
        int x = count(s.begin(), s.end(), t[0]);
        x = min(m + x, n);
        cout << x * (x - 1) / 2;
        return;
    }

    int x = -1e9;
    v dp(n + 1, v(m + 1, v(n + 2, array<int, 3>{x, x, x})));
    for (int i = 0; i <= m; i++)
        dp[0][i][0] = {0, 0, 0};
    
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= n; k++) {

                if (s[i - 1] == t[1])
                    dp[i][j][k][0] = max({
                        dp[i][j][k][0],
                        dp[i - 1][j][k][0] + k,
                        dp[i - 1][j][k][1] + k,
                        dp[i - 1][j][k][2] + k
                    });
                else if (s[i - 1] == t[0])
                    dp[i][j][k + 1][0] = max({
                        dp[i][j][k + 1][0],
                        dp[i - 1][j][k][0],
                        dp[i - 1][j][k][1],
                        dp[i - 1][j][k][2]
                    });
                else
                    dp[i][j][k][0] = max({
                        dp[i][j][k][0],
                        dp[i - 1][j][k][0],
                        dp[i - 1][j][k][1],
                        dp[i - 1][j][k][2]
                    });

                if (j) {
                    dp[i][j][k + 1][1] = max({
                        dp[i][j][k + 1][1],
                        dp[i - 1][j - 1][k][0],
                        dp[i - 1][j - 1][k][1],
                        dp[i - 1][j - 1][k][2]
                    });
                    dp[i][j][k][2] = max({
                        dp[i][j][k][2],
                        dp[i - 1][j - 1][k][0] + k,
                        dp[i - 1][j - 1][k][1] + k,
                        dp[i - 1][j - 1][k][2] + k
                    });
                }
            }
    
    int ans = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 3; j++)
            ans = max(ans, dp[n][m][i][j]);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}