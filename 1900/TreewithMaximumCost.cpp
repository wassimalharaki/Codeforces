#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    v<int> cnt(n), dp(n);
    auto dfs1 = [&](int u, int p, int d, auto&& dfs) -> void {
        dp[0] += d * a[u];
        cnt[u] += a[u];
        for (int& i : adj[u]) if (i != p) {
            dfs(i, u, d + 1, dfs);
            cnt[u] += cnt[i];
        }
    };
    dfs1(0, -1, 0, dfs1);

    int ans = 0;
    auto dfs2 = [&](int u, int p, auto&& dfs) -> void {
        if (p != -1) {
            dp[u] = dp[p] + cnt[p] - 2 * cnt[u];
            cnt[u] = cnt[p];
        }
        ans = max(ans, dp[u]);
        for (int& i : adj[u])
            if (i != p)
                dfs(i, u, dfs);
    };
    dfs2(0, -1, dfs2);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}