#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m, y; cin >> n >> m >> y;
    v base(m / 2 + 1, v(m + 1, v<int>(y, INT_MIN)));
    for (int i = 0; i <= m / 2; i++)
        for (int j = 0; j <= m; j++)
            base[i][j][0] = 0;

    v<int> ans(y, INT_MIN), nans(y);
    ans[0] = 0;
    for (int _ = 0; _ < n; _++) {
        auto dp = base;

        v<int> a(m);
        for (int& x : a) cin >> x;

        for (int i = 1; i <= m / 2; i++)
            for (int j = 1; j <= m; j++)
                for (int k = 0; k < y; k++)
                    dp[i][j][(k + a[j - 1]) % y] = max({
                        dp[i - 1][j - 1][k] + a[j - 1],
                        dp[i][j - 1][(k + a[j - 1]) % y],
                        dp[i - 1][j][(k + a[j - 1]) % y]
                    });
        
        copy(ans.begin(), ans.end(), nans.begin());
        for (int i = 0; i < y; i++)
            for (int j = 0; j < y; j++)
                nans[(i + j) % y] = max(nans[(i + j) % y], dp.back().back()[i] + ans[j]);
        ans.swap(nans);
    }
    cout << ans[0] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}