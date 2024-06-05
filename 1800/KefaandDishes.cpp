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

    v<int> a(n);
    for (int& x : a) cin >> x;

    v adj(n, v<int>(n));
    for (int i = 0; i < k; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a - 1][b - 1] = c;
    }

    int ans = 0;
    v dp(n, v<int>(1 << n));
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i][1 << i] = a[i]);

    for (int mask = 0; mask < (1 << n); mask++)
        if (__builtin_popcountll(mask) <= m)
            for (int i = 0; i < n; i++)
                if ((1 << i) & mask)
                    for (int j = 0; j < n; j++)
                        if ((1 << j) & (mask ^ (1 << i)))
                            ans = max(
                                ans, 
                                dp[i][mask] = max(
                                    dp[i][mask], 
                                    a[i] + adj[j][i] + dp[j][mask ^ (1 << i)]
                                )
                            );
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}