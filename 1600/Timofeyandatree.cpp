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

    v<v<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    v<int> color(n + 1), bad(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> color[i];

    auto dfs_bad = [&](int u, int p, auto&& dfs_bad) -> void {
        for (int& i : adj[u]) if (i != p) {
            dfs_bad(i, u, dfs_bad);
            bad[u] += bad[i] + (color[u] != color[i]);
        }
    };
    dfs_bad(1, 0, dfs_bad);
    bad[0] = bad[1];

    int ans = -1;
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        int x = 0;
        for (int& i : adj[u]) {
            x += bad[i];
            if (i == p)
                x -= bad[u] + (color[i] != color[u]);
        }
        if (x == 0) ans = u;
        
        bad[u] = bad[p];
        for (int& i : adj[u]) if (i != p)
            dfs(i, u, dfs);
    };
    dfs(1, 0, dfs);

    if (ans == -1)
        cout << "NO" << nl;
    else
        cout << "YES" << nl << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}