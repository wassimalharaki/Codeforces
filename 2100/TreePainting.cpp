#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v<int> dp(n), sz(n);
    auto dfs = [&](int u, int p, auto&& dfs) -> int {
        sz[u] = 1;
        for (int& i : adj[u]) if (i != p) {
            sz[u] += dfs(i, u, dfs);
            dp[u] += dp[i];
        }
        dp[u] += sz[u];
        return sz[u];
    };
    dfs(0, -1, dfs);

    int ans = 0;
    auto reroot = [&](int u, int p, auto&& reroot) -> void {
        if (p != -1) {
            sz[p] -= sz[u];
            dp[p] -= sz[u];
            dp[p] -= dp[u];

            sz[u] += sz[p];
            dp[u] += sz[p];
            dp[u] += dp[p];
        }
        ans = max(ans, dp[u]);

        for (int& i : adj[u])
            if (i != p) reroot(i, u, reroot);
        
        if (p != -1) {
            dp[u] -= dp[p];
            dp[u] -= sz[p];
            sz[u] -= sz[p];

            dp[p] += dp[u];
            dp[p] += sz[u];
            sz[p] += sz[u];
        }
    };
    reroot(0, -1, reroot);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}