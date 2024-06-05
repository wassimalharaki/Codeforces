#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v<int> dp(n), vis(n);
    auto dfs1 = [&](int u, int p, auto&& dfs) -> void {
        dp[u] += (a[u] ? 1 : -1);

        for (int& i : adj[u])
            if (i != p) {
                dfs(i, u, dfs);
                dp[u] += max(0, dp[i]);
                vis[i] = dp[i] > 0;
            }
    };
    dfs1(0, -1, dfs1);

    auto dfs2 = [&](int u, int p, auto&& dfs) -> void {
        if (p != -1)
            dp[u] += max(0, dp[p] - (vis[u] ? dp[u] : 0));

        for (int& i : adj[u])
            if (i != p)
                dfs(i, u, dfs);
    };
    dfs2(0, -1, dfs2);

    for (int& x : dp)
        cout << x << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}