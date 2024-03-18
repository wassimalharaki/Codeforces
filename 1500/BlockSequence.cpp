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

    v<int> dp(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = 1 + dp[i + 1];
        if (i + nums[i] + 1 <= n)
            dp[i] = min(dp[i], dp[i + nums[i] + 1]);
    }
    cout << dp[0] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}