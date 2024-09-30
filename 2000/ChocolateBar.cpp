#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

v dp(31, v(31, v<int>(51, -1)));

int f(int n, int m, int k) {
    if (n < 0 or m < 0 or k < 0)
        return INT_MAX;
    
    if (dp[n][m][k] != -1)
        return dp[n][m][k];
    
    if (k > n * m)
        return dp[n][m][k] = INT_MAX;

    if (k == 0)
        return dp[n][m][k] = 0;

    if (n * m == k)
        return dp[n][m][k] = 0;

    dp[n][m][k] = INT_MAX;
    for (int i = 1; i < n; i++) {
        int up = i * m, down = (n - i) * m;

        dp[n][m][k] = min(dp[n][m][k], m * m + f(n - i, m, k - up));
        dp[n][m][k] = min(dp[n][m][k], m * m + f(i, m, k - down));

        for (int j = 0; j <= k; j++)
            dp[n][m][k] = min(dp[n][m][k], m * m + f(i, m, j) + f(n - i, m, k - j));
    }

    for (int i = 1; i < m; i++) {
        int left = i * n, right = (m - i) * n;

        dp[n][m][k] = min(dp[n][m][k], n * n + f(n, m - i, k - left));
        dp[n][m][k] = min(dp[n][m][k], n * n + f(n, m, k - right));

        for (int j = 0; j <= k; j++)
            dp[n][m][k] = min(dp[n][m][k], n * n + f(n, i, j) + f(n, m - i, k - j));
    }

    return dp[n][m][k];
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    cout << f(n, m, k) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}