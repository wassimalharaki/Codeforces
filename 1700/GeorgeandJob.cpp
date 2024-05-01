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
    int n, m, k; cin >> n >> m >> k;

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    v<v<int>> dp(n, v<int>(k + 1));
    int sum = 0;
    for (int i = 0; i < m; i++)
        sum += nums[i];

    fill(dp[m - 1].begin() + 1, dp[m - 1].end(), sum);
    for (int i = m; i < n; i++) {
        sum -= nums[i - m];
        sum += nums[i];
        for (int j = 1; j <= k; j++)
            dp[i][j] = max(sum + dp[i - m][j - 1], dp[i - 1][j]);;
    }
    
    cout << dp[n - 1][k] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}