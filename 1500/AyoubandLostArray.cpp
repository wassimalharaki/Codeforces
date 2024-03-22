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

const int mod = 1e9 + 7;

void solve() {
    int n, l, r; cin >> n >> l >> r;
    int zero = r / 3 - (l - 1) / 3;
    int one = (r + 2) / 3 - (l + 1) / 3;
    int two = (r + 1) / 3 - l / 3;
    
    int dp[n + 1][3];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = (dp[i - 1][0] * zero % mod + dp[i - 1][1] * two % mod + dp[i - 1][2] * one % mod) % mod;
        dp[i][1] = (dp[i - 1][0] * one % mod + dp[i - 1][1] * zero % mod + dp[i - 1][2] * two % mod) % mod;
        dp[i][2] = (dp[i - 1][0] * two % mod + dp[i - 1][1] * one % mod + dp[i - 1][2] * zero % mod) % mod;
    }
    cout << dp[n][0] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}