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

v<int> get_cycles(v<v<int>>& adj) {
    int n = adj.size();

    v<char> c(n);
    v<int> cycle_heads;
    auto dfs = [&](int u, auto&& dfs) -> void {
        c[u] = 1;
        for (int& i : adj[u])
            if (c[i] == 1)
                cycle_heads.push_back(i);
            else if (c[i] == 0)
                dfs(i, dfs);
        c[u] = 2;
    };

    for (int i = 0; i < n; i++)
        if (c[i] == 0)
            dfs(i, dfs);
    return cycle_heads;
}

// O(V + E)
v<int> topsort(v<v<int>>& adj) {
    int n = adj.size();
    v<char> vis(n);
    v<int> order;

    auto dfs = [&](int u, auto&& dfs) -> void {
        vis[u] = 1;
        for (int& i : adj[u])
            if (not vis[i])
                dfs(i, dfs);
        order.push_back(u);
    };

    for (int i = 0; i < n; i++)
        if (not vis[i]) dfs(i, dfs);
    reverse(order.begin(), order.end());

    return order;
}

void solve() {
    int n; cin >> n;

    v<int> a(n);
    v<v<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int u; cin >> u;
        adj[i].push_back(u - 1);
    }
    for (int& x : a) cin >> x;

    auto cycles = get_cycles(adj);
    v<char> vis(n);
    for (int& u : cycles) {
        int i = u;
        while (not vis[u]) {
            vis[u] = 1;
            if (a[u] < a[i])
                i = u;
            u = adj[u][0];
        }
        adj[i].clear();
    }

    auto order = topsort(adj);
    for (int& u : order)
        cout << u + 1 << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}