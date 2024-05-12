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
    int n, m; cin >> n>> m;

    v<v<array<int, 3>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back({b, i, 1});
        adj[b].push_back({a, i, 0});
    }

    v<int> ans(m, -1), out(n), in(n), vis(n);
    auto dfs = [&](int u, int p, bool b, auto&& dfs) -> void {
        vis[u] = 1;
        for (auto& [i, j, k] : adj[u])
            if (ans[j] == -1) {
                if (b) 
                    out[u]++, in[i]++;
                else
                    in[u]++, out[i]++;
                ans[j] = (k ? b : !b);
                
                if (not vis[i])
                    dfs(i, u, !b, dfs);
            }
    };
    dfs(0, -1, 1, dfs);

    for (int i = 0; i < n; i++)
        if (in[i] and out[i]) {
            cout << "NO" << nl;
            return;
        }

    cout << "YES" << nl;
    for (int& a : ans)
        cout << a;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}