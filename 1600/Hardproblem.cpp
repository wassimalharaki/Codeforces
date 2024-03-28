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
    v<array<string, 2>> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i][0];
        s[i][1] = s[i][0];
        reverse(all(s[i][1]));
    }

    v<array<int, 2>> dp(n, {0, 0});
    dp[0] = {0, nums[0]};
    for (int i = 1; i < n; i++) {
        bool x = s[i][0] >= s[i - 1][0];
        bool y = s[i][0] >= s[i - 1][1];
        if (x and y)
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
        else if (x)
            dp[i][0] = dp[i - 1][0];
        else if (y)
            dp[i][0] = dp[i - 1][1];
        else
            dp[i][0] = 1e16;
        
        x = s[i][1] >= s[i - 1][0];
        y = s[i][1] >= s[i - 1][1];
        dp[i][1] = nums[i];
        if (x and y)
            dp[i][1] += min(dp[i - 1][0], dp[i - 1][1]);
        else if (x)
            dp[i][1] += dp[i - 1][0];
        else if (y)
            dp[i][1] += dp[i - 1][1];
        else
            dp[i][1] = 1e16;
    }
    int ans = min(dp[n - 1][0], dp[n - 1][1]);
    cout << (ans >= 1e16 ? -1 : ans);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}