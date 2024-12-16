#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v dp(n, v<int>(n, INT_MIN));
    for (int i = 0; i < n; i++)
        dp[i][i] = a[i];

    for (int i = 1; i < n; i++)
        for (int j = 0; j + i < n; j++)
            for (int k = j + 1; k <= j + i; k++) {
                if (dp[j][k - 1] > 0 and dp[j][k - 1] == dp[k][j + i]) {
                    dp[j][j + i] = dp[j][k - 1] + 1;
                    break;
                }
                dp[j][j + i] = max(dp[j][j + i], min(dp[j][k - 1], -1) + min(dp[k][j + i], -1));
            }
    cout << - min(dp[0][n - 1], - 1) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}