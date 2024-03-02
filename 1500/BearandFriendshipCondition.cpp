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
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    v<bool> vis(n + 1);
    int x = 0, y = 0;
    auto dfs = [&](int u, auto&& dfs) -> void {
        vis[u] = 1;
        x++;
        y += adj[u].size();
        for (int& i : adj[u])
            if (not vis[i])
                dfs(i, dfs);
    };

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        x = 0, y = 0;
        dfs(i, dfs);
        if (x <= 2) continue;
        if (y != (x - 1) * x) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}