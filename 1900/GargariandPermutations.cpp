#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, k; cin >> n >> k;

    v<v<int>> a(k, v<int>(n)), cnt(n, v<int>(n));
    for (auto& x : a)
        for (int& y : x)
            cin >> y, y--;

    for (auto& x : a)
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                cnt[x[i]][x[j]]++;

    v<v<int>> adj(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (cnt[i][j] == k)
                adj[i].push_back(j);

    v<int> dp(n);
    auto dfs = [&](int u, auto&& dfs) -> int {
        if (dp[u]) return dp[u];
        dp[u] = 1;
        for (int& i : adj[u])
            dp[u] = max(dp[u], 1 + dfs(i, dfs));
        return dp[u];
    };

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dfs(i, dfs));
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}