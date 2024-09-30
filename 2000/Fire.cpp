#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    int m = 0;
    v<array<int, 4>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2], a[i][3] = i + 1;
        m = max(m, a[i][1]);
    }
    sort(a.begin(), a.end(), [](auto x, auto y)
        { return x[1] < y[1]; });

    v dp(n + 1, v(m + 1, array<int, 4>{0, 0, -1, -1}));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j - 1][0] > dp[i - 1][j][0])
                dp[i][j] = {dp[i][j - 1][0], 0, i, j - 1};
            else
                dp[i][j] = {dp[i - 1][j][0], 0, i - 1, j};
            
            int t = min(a[i - 1][1] - a[i - 1][0] - 1, j - a[i - 1][0]);
            if (t >= 0) {
                int c = dp[i - 1][t][0] + a[i - 1][2];
                if (c > dp[i][j][0])
                    dp[i][j] = {c, 1, i - 1, t};
            }
        }
    }

    int i = n, j = m;
    v<int> ans;
    while (i and j) {
        if (dp[i][j][1])
            ans.push_back(a[i - 1][3]);
        tie(i, j) = {dp[i][j][2], dp[i][j][3]};
    }
    reverse(ans.begin(), ans.end());

    cout << dp[n][m][0] << nl;
    cout << ans.size() << nl;
    for (int& x : ans)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}