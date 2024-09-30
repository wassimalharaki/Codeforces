#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, k; cin >> n >> k;

    v<int> a(n);
    for (int& x : a)
        cin >> x, x--;

    v dp(n + 1, v<int>(n, INT_MAX));
    for (int i = 0; i < n; i++)
        dp[0][i] = (a[i] == i) + (i ? dp[0][i - 1] : 0);
    
    for (int i = 1; i <= n; i++) {
        dp[i][i - 1] = 0;
        for (int j = i; j < n; j++)
            dp[i][j] = max((a[j] == j - i) + dp[i][j - 1], dp[i - 1][j - 1]);
    }

    for (int i = 0; i <= n; i++)
        if (dp[i][n - 1] >= k) {
            cout << i << nl;
            return;
        }
    cout << -1 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}