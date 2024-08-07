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

// O(nlog(n)), O(1)
struct LCA {
    using ai2 = array<int, 2>;
    v<int> in, depth;
    v<v<ai2>> d;

    LCA(v<v<int>>& adj, int root = 0) {
        in.resize(adj.size());
        depth.resize(adj.size());

        v<ai2> path;
        auto dfs = [&](int u, int p, int h, auto&& dfs) -> void {
            in[u] = path.size();
            depth[u] = h;
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
        d.resize(k, v<ai2>(n));
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

    int dist(int a, int b) {
        return depth[a] + depth[b] - 2 * depth[prod(a, b)];
    }
};

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    LCA lca(adj);

    while (m--) {
        int k; cin >> k;
        v<array<int, 2>> a(k);
        for (auto& x : a) {
            cin >> x[1];
            x[0] = lca.depth[--x[1]];
        }
        sort(a.rbegin(), a.rend());

        bool ok = 1;
        int u = a[0][1];
        for (int i = 1; i < k; i++) {
            u = lca.prod(u, a[i][1]);
            if (lca.dist(u, a[i][1]) > 1)
                ok = 0;
        }
        cout << (ok ? "YES" : "NO") << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}