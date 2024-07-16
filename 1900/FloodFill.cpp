#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<v<array<int, 2>>> dp(n, v<array<int, 2>>(n));
    for (int i = 1; i < n; i++)
        for (int j = 0; j + i < n; j++)
            dp[j][j + i] = {
                min(
                    dp[j + 1][j + i][0] + (a[j] != a[j + 1]),
                    dp[j + 1][j + i][1] + (a[j] != a[j + i])
                ),
                min(
                    dp[j][j + i - 1][0] + (a[j + i] != a[j]),
                    dp[j][j + i - 1][1] + (a[j + i] != a[j + i - 1])
                )
            };
    cout << min(dp[0][n - 1][0], dp[0][n - 1][1]) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}