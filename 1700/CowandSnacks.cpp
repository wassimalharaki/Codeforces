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
    int n, k; cin >> n >> k;

    v<array<int, 2>> a(k);
    v<v<int>> adj(n + 1);
    for (int i = 0; i < k; i++) {
        cin >> a[i][0] >> a[i][1];
        adj[a[i][0]].push_back(i);
        adj[a[i][1]].push_back(i);
    }

    int ans = 0;
    v<bool> dead(k), vis(n + 1);
    auto dfs = [&](int u, auto&& dfs) -> void {
        for (int& i : adj[u])
            if (not dead[i]) {
                dead[i] = 1;
                auto& [x, y] = a[i];
                if (not vis[x] and not vis[y]) {
                    vis[x] = vis[y] = 1;
                    if (x != u) dfs(x, dfs);
                    if (y != u) dfs(y, dfs);
                }
                else if (vis[x] and not vis[y]) {
                    vis[y] = 1;
                    dfs(y, dfs);
                }
                else if (not vis[x] and vis[y]) {
                    vis[x] = 1;
                    dfs(x, dfs);
                }
                else
                    ans++;
            }
    };

    for (int i = 1; i <= n; i++)
        if (not vis[i])
            dfs(i, dfs);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}