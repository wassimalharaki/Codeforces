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

    v<v<array<int, 2>>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    v<array<int, 2>> dp(n);
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        for (auto& [i, w] : adj[u]) if (i != p) {
            dfs(i, u, dfs);
            dp[u][0] += dp[i][0] + 2 * w;
            dp[u][1] = max(dp[u][1], w + dp[i][1]);
        }
    };
    dfs(0, -1, dfs);
    cout << dp[0][0] - dp[0][1];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}