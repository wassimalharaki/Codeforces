#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int mod = 1e9 + 7;

v<v<int>> multiply(v<v<int>>& a, v<v<int>>& b) {
    int n = a.size();
    v res(n, v<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
    return res;
}

v<v<int>> binpow(v<v<int>> a, int b, const int m = mod) {
    int n = a.size();
    v res(n, v<int>(n));
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    while (b) {
        if (b & 1)
            res = multiply(res, a);
        a = multiply(a, a);
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, m; cin >> n >> m;

    if (n < m) {
        cout << 1 << nl;
        return;
    }

    v<v<int>> dp(m, v<int>(m));
    for (int i = 0; i < m - 1; i++)
        dp[i][i + 1] = 1;
    dp[m - 1][m - 1] = 1;
    dp[m - 1][0] = 1;
    dp = binpow(dp, n - m + 1, mod);

    int ans = 0;
    for (int i = 0; i < m; i++)
        ans = (ans + dp[m - 1][i]) % mod;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}