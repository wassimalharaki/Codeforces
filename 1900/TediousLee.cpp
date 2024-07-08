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

const int mod = 1e9 + 7;
const int N = 2e6 + 1;
v<array<int, 3>> dp(N);
v<int> ans(N);

void solve() {
    int n; cin >> n;
    cout << ans[n] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // {leaf, 1 child, 3 children}
    dp[1] = {1, 0, 0};
    for (int i = 2; i < N; i++) {
        dp[i] = {
            (2 * dp[i - 1][1] + dp[i - 1][0]) % mod,
            dp[i - 1][0],
            (dp[i - 1][2] + dp[i - 1][1]) % mod
        };
        ans[i] = ((i - 3 >= 0 ? ans[i - 3] : 0) + dp[i - 1][1] * 4) % mod;
    }

    int T = 1;
    cin >> T;
    while (T--) solve();
}