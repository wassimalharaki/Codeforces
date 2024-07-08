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

    v<int> a(n);
    for (int& x : a) cin >> x;

    v dp(n, v<array<int, 2>>(n, {INT_MAX, INT_MAX}));
    for (int i = 0; i < n; i++)
        dp[i][i] = {1, 0};
    for (int i = 0; i < n - 1; i++)
        if (a[i] == a[i + 1])
            dp[i][i + 1] = {1, 0};
        else
            dp[i][i + 1] = {2, 1};

    for (int i = 2; i < n; i++)
        for (int j = 0; j + i < n; j++) {
            if (a[j] == a[j + i])
                dp[j][j + i] = {1 + dp[j + 1][j + i - 1][1], dp[j + 1][j + i - 1][1]};
            for (int k = j; k < j + i; k++)
                dp[j][j + i] = min({
                    dp[j][j + i],
                    {dp[j][k][0] + dp[k + 1][j + i][0], dp[j][k][1] + dp[k + 1][j + i][0]},
                    {dp[j][k][0] + dp[k + 1][j + i][0], dp[j][k][0] + dp[k + 1][j + i][1]}
                });
        }
    cout << dp[0][n - 1][0] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}