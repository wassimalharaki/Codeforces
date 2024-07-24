#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<v<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int p; cin >> p; p--;
        adj[p].push_back(i);
    }
    
    v<int> a(n);
    for (int& x : a) cin >> x;

    v<array<int, 3>> dp(n);
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        if (adj[u].empty()) {
            dp[u] = {a[u], 0, 1};
            return;
        }

        for (int& i : adj[u]) {
            dfs(i, u, dfs);
            dp[u][0] = max(dp[u][0], dp[i][0]);
            dp[u][1] += dp[i][1];
            dp[u][2] += dp[i][2];
        }

        for (int& i : adj[u])
            dp[u][1] += dp[i][2] * (dp[u][0] - dp[i][0]);
        
        int sub = min(a[u], dp[u][1]);
        a[u] -= sub, dp[u][1] -= sub;

        dp[u][0] += (a[u] + dp[u][2] - 1) / dp[u][2];
        dp[u][1] += (dp[u][2] - a[u] % dp[u][2]) % dp[u][2];
    };
    dfs(0, -1, dfs);

    cout << dp[0][0] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}