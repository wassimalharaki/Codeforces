#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, k; cin >> n >> k;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v rem(n, v<int>(k));
    v<int> dp(n);
    auto dfs = [&](int u, int p, auto&& self) -> void {
        rem[u][0] = 1;
        for (int& i : adj[u]) if (i != p) {
            self(i, u, self);
            for (int j = 0; j < k; j++)
                rem[u][(j + 1) % k] += rem[i][j];
            dp[u] += dp[i] + rem[i][k - 1];
        }
    };
    dfs(0, -1, dfs);

    int ans = 0;
    auto reroot = [&](int u, int p, auto&& self) -> void {
        if (p != -1) {
            for (int j = 0; j < k; j++)
                rem[p][(j + 1) % k] -= rem[u][j];
            dp[p] -= dp[u] + rem[u][k - 1];

            for (int j = 0; j < k; j++)
                rem[u][(j + 1) % k] += rem[p][j];
            dp[u] += dp[p] + rem[p][k - 1];
        }
        int x = dp[u];
        ans += dp[u];
        for (int i = 1; i < k; i++)
            ans += rem[u][i], x += rem[u][i];
        
        for (int& i : adj[u])
            if (i != p) self(i, u, self);
        
        if (p != -1) {
            for (int j = 0; j < k; j++)
                rem[u][(j + 1) % k] -= rem[p][j];
            dp[u] -= dp[p] + rem[p][k - 1];

            for (int j = 0; j < k; j++)
                rem[p][(j + 1) % k] += rem[u][j];
            dp[p] += dp[u] + rem[u][k - 1];
        }
    };
    reroot(0, -1, reroot);
    cout << ans / 2 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}