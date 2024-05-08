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
    int n, k; cin >> n >> k;

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    if (n == 1) {
        cout << nums[0] << nl;
        return;
    }

    v<v<int>> dp(n + 1, v<int>(k + 1));
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + nums[i - 1];
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j] + nums[i - 1];
            int mn = nums[i - 1];
            for (int m = 1; m <= j and i - m - 1 >= 0; m++) {
                mn = min(mn, nums[i - m - 1]);
                dp[i][j] = min(dp[i][j], mn * (m + 1) + dp[i - m - 1][j - m]);
            }
        }
    }
    cout << dp[n][k] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}