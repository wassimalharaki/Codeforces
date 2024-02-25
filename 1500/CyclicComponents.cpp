#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> adj(n + 1);
    v<bool> vis(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool ok = 1;
    auto dfs = [&](int u, auto&& dfs) -> void {
        ok &= adj[u].size() == 2;
        vis[u] = 1;
        for (auto& i : adj[u])
            if (not vis[i])
                dfs(i, dfs);
    };

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (not vis[i]) {
            ok = 1;
            dfs(i, dfs);
            ans += ok;
        }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}