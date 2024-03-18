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

void solve() {
    int n; cin >> n;
    v<int> nums(n);
    for (int& a : nums) cin >> a;

    v<array<int, 2>> dp(n + 2);
    for (int i = n - 1; i >= 0; i--) {
        dp[i][1] = max(nums[i] + max(dp[i + 1][1], dp[i + 2][1]), dp[i + 1][0]);
        dp[i][0] = max(dp[i + 1][0], dp[i + 1][1]);
    }
    cout << dp[0][1] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}