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
    int n; cin >> n;

    v<int> a(n), dp(n + 1);
    v<array<int, 2>> l(n);
    for (int& x : a) cin >> x;

    l[0] = {a[0] == 0 ? 0 : -1, a[0] == 2};
    for (int i = 1; i < n; i++)
        if (a[i] == 0)
            l[i] = {i, 0};
        else
            l[i] = l[i - 1], l[i][1] |= a[i] == 2;

    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = 1 + dp[max(0ll, l[i - 1][0])];
        if (a[i - 2] == 1) {
            if (l[i - 2][1])
                dp[i] = min(dp[i], dp[i - 1]);
            else
                dp[i] = min(dp[i], 1 + dp[l[i - 2][0] + 1]);
        }
        if (a[i - 2] == 2)
            dp[i] = min(dp[i], dp[i - 1]);
    }
    cout << dp[n] << nl;
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}