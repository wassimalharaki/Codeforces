#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int l, n, m; cin >> l >> n >> m;

    v<int> a(l);
    for (int& x : a) cin >> x;

    v<v<int>> b(n, v<int>(m));
    for (auto& x : b)
        for (auto& y : x)
            cin >> y;
    
    v dp(n, v(m, v<char>(l)));
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--)
            for (int k = l - 1; k >= 0; k--) {
                if (a[k] == b[i][j]) {
                    if (i == n - 1 or j == m - 1 or k == l - 1)
                        dp[i][j][k] = 1;
                    else
                        dp[i][j][k] = !dp[i + 1][j + 1][k + 1];
                }
                if (i < n - 1)
                    dp[i][j][k] |= dp[i + 1][j][k];
                if (j < m - 1)
                    dp[i][j][k] |= dp[i][j + 1][k];
                if (i < n - 1 and j < m - 1)
                    dp[i][j][k] |= dp[i + 1][j + 1][k];
            }
    cout << (dp[0][0][0] ? "T" : "N") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}