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
    int n, x; cin >> n >> x;

    v<int> cost(n), prize(n);
    for (int i = 0; i < n; i++)
        cin >> cost[i] >> prize[i];
    int m = accumulate(prize.begin(), prize.end(), 0ll) + 1;

    v<v<int>> dp(n, v<int>(m));
    dp[0][0] = x;
    int ans = 0;
    if (cost[0] == 0)
        dp[0][prize[0]] = x, ans = prize[0];

    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (dp[i - 1][j] == 0) continue;
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + x);

            if (dp[i - 1][j] >= cost[i]) {
                ans = max(ans, j + prize[i]);
                dp[i][j + prize[i]] = max(dp[i][j + prize[i]], dp[i - 1][j] - cost[i] + x);
            }
        }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}