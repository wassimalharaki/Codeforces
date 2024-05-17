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
    int n, l, k; cin >> n >> l >> k;

    v<int> d(n), a(n);
    for (int& x : d) cin >> x;
    for (int& x : a) cin >> x;
    d.push_back(l);

    v<v<int>> dp(k + 1, v<int>(n));
    for (int i = 0; i <= k; i++)
        dp[i][0] = d[1] * a[0];

    for (int i = 0; i <= k; i++)
        for (int j = 1; j < n; j++) {
            int x = d[j + 1] - d[j];
            dp[i][j] = dp[i][j - 1] + x * a[j];

            for (int m = j - 1; m >= max(j - i, 0ll); m--) {
                dp[i][j] = min(dp[i][j], dp[i - (j - m)][m] + a[m] * x);
                x += d[m + 1] - d[m];
            }
        }
    cout << dp[k].back() << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}