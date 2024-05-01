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

const int mod = 1e8;
int dp[101][101][11][11];

void solve() {
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= k1; i++)
        dp[i][0][i][0] = 1;
    for (int i = 0; i <= k2; i++)
        dp[0][i][0][i] = 1;

    for (int i = 1; i <= n1; i++)
        for (int j = 1; j <= n2; j++) {
            for (int k = 0; k <= k2; k++)
                dp[i][j][1][0] = (dp[i][j][1][0] + dp[i - 1][j][0][k]) % mod;
            for (int k = 0; k <= k1; k++)
                dp[i][j][0][1] = (dp[i][j][0][1] + dp[i][j - 1][k][0]) % mod;
            for (int k = 2; k <= k1; k++)
                dp[i][j][k][0] = dp[i - 1][j][k - 1][0];
            for (int k = 2; k <= k2; k++)
                dp[i][j][0][k] = dp[i][j - 1][0][k - 1];
        }

    int ans = 0;
    for (int k = 0; k <= k1; k++)
        ans = (ans + dp[n1][n2][k][0]) % mod;
    for (int k = 0; k <= k2; k++)
        ans = (ans + dp[n1][n2][0][k]) % mod;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}