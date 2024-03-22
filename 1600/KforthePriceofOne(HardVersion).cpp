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
    int n, p, k; cin >> n >> p >> k;
 
    v<int> nums(n);
    for (int& a : nums) cin >> a;
    sort(all(nums));
 
    v<int> dp(n + 1);
    for (int i = 0; i < k - 1; i++)
        dp[i + 1] = dp[i] + nums[i];
    for (int i = k; i <= n; i++)
        dp[i] = nums[i - 1] + dp[i - k];
        
    int ans = 0;
    for (int i = 0; i <= n; i++)
        if (dp[i] <= p) ans = i;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}