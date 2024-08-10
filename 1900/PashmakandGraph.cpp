#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    v<array<int, 3>> e(m);
    for (auto& [c, a, b] : e)
        cin >> a >> b >> c, a--, b--;
    sort(e.rbegin(), e.rend());

    int ans = 0;
    v<v<array<int, 2>>> dp(n);
    for (auto& [c, i, j] : e) {
        auto it = lower_bound(dp[j].rbegin(), dp[j].rend(),
                array{c, INT_MAX});

        int x = 1 + (it == dp[j].rend() ? 0 : (*it)[1]);
        if (dp[i].empty() or x > dp[i].back()[1])
            dp[i].push_back({c, x});
        ans = max(ans, x);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}