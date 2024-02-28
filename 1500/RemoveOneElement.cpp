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

    v<array<int, 3>> dp(n);
    dp[0] = {1, 1, 1};
    dp[1] = {1 + (nums[1] > nums[0]), 1, 1};
    int ans = max(1ll, dp[1][0]);
    for (int i = 2; i < n; i++) {
        int a = 1 + (nums[i] > nums[i - 1] ? dp[i - 1][0] : 0);
        int b = 1 + (nums[i] > nums[i - 1] ? max(dp[i - 1][1], dp[i - 1][2]) : 0);
        int c = 1 + (nums[i] > nums[i - 2] ? dp[i - 2][0] : 0);
        dp[i] = {a, b, c};
        ans = max({ans, a, b, c});
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}