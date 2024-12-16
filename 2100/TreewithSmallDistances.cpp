#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<v<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v<array<int, 4>> dp(n);
    auto dfs =  [&](int u, int p, int d, auto&& self) -> void {
        dp[u] = {-1, d > 1, 0, 0};

        int mn = INT_MAX;
        for (int& i : adj[u]) {
            if (i == p) continue;
            self(i, u, d + 1, self);
            dp[u][1] += min({dp[i][1], dp[i][2], dp[i][3]});
            dp[u][2] += min(dp[i][1], dp[i][2]);
            dp[u][3] += min(dp[i][1], dp[i][2]);
            mn = min(mn, dp[i][1] - dp[i][2]);
        }
        dp[u][2] += max(0ll, mn);
    };
    dfs(0, -1, 0, dfs);
    cout << dp[0][1] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}