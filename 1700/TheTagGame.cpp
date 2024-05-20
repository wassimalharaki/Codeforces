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

struct LCA {
    using ai2 = array<int, 2>;
    v<int> in;
    v<v<ai2>> d;

    LCA(v<v<int>>& adj, int root = 0) {
        in.resize(adj.size());
 
        v<ai2> path;
        auto dfs = [&](int u, int p, int h, auto&& dfs) -> void {
            in[u] = path.size();
            path.push_back({u, h});
 
            for (int& i : adj[u])
                if (i != p) {
                    dfs(i, u, h + 1, dfs);
                    path.push_back({u, h});
                }
        };
        dfs(root, -1, 0, dfs);
        build(path);
    }

    ai2 op(ai2& l, ai2& r) {
        return l[1] < r[1] ? l : r;
    }

    void build(v<ai2>& a) {
        int n = a.size(), k = 64 - __builtin_clzll(n);
        d = v<v<ai2>>(k, v<ai2>(n));
        copy(a.begin(), a.end(), d[0].begin());
 
        for (int i = 1; i <= k; i++)
            for (int j = 0; j + (1 << i) <= n; j++)
                d[i][j] = op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);
    }

    int prod(int a, int b) {
        int l = in[a], r = in[b];
        if (l > r) swap(l, r);
        int i = 63 - __builtin_clzll(++r - l);
        return op(d[i][l], d[i][r - (1 << i)])[0];
    }
};

void solve() {
    int n, x; cin >> n >> x; x--;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    LCA lca(adj);

    v<int> h(n);
    auto dfs = [&](int u, int p, int d, auto&& dfs) -> void {
        h[u] = d;
        for (int& i : adj[u])
            if (i != p)
                dfs(i, u, d + 1, dfs);
    };
    dfs(0, -1, 0, dfs);

    auto dist = [&](int a, int b) {
        return h[a] + h[b] - 2 * h[lca.prod(a, b)];
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a = dist(0, i);
        int b = dist(x, i);
        if (a <= b) continue;
        ans = max(ans, dist(0, i) * 2);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}