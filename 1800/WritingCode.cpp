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
    int n, m, b, z;
    cin >> n >> m >> b >> z;
    const int mod = z;

    v<int> a(n);
    for (int& x : a) cin >> x;

    auto add = [&](int& a, int b) {
        a = (a + b) % mod;
    };

    v dp(m + 1, v<int>(b + 1));
    dp[0][0] = 1;
    for (int& x : a)
        for (int i = 0; i < m; i++)
            for (int j = 0; j + x <= b; j++)
                add(dp[i + 1][j + x], dp[i][j]);

    int ans = 0;
    for (int& x : dp[m])
        add(ans, x);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}