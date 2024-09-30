#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

// O(nlog(n)), O(1)
struct LCA {
    using ai2 = array<int, 2>;
    vector<int> in, dep;
    vector<vector<ai2>> d;

    LCA(vector<vector<int>>& adj, int root = 0) {
        in.resize(adj.size());
        dep.resize(adj.size());

        vector<ai2> path;
        auto dfs = [&](int u, int p, int h, auto&& dfs) -> void {
            in[u] = path.size();
            dep[u] = h;
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

    void build(vector<ai2>& a) {
        int n = a.size(), k = 1 + (n ? __lg(n) : 0);
        d.resize(k, vector<ai2>(n));
        copy(a.begin(), a.end(), d[0].begin());

        for (int i = 1; i <= k; i++)
            for (int j = 0; j + (1 << i) <= n; j++)
                d[i][j] = op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);
    }

    int prod(int a, int b) {
        int l = in[a], r = in[b];
        if (l > r) swap(l, r);
        int i = __lg(++r - l);
        return op(d[i][l], d[i][r - (1 << i)])[0];
    }

    int dis(int a, int b) {
        return dep[a] + dep[b] - 2 * dep[prod(a, b)];
    }
};

void solve() {
    int n; cin >> n;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    LCA lca(adj);

    int Q; cin >> Q;
    while (Q--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        a--, b--, x--, y--;

        int p = lca.dis(a, b);
        int q = lca.dis(a, x) + 1 + lca.dis(y, b);
        int r = lca.dis(a, y) + 1 + lca.dis(x, b);
        int s = lca.dis(a, x) + 1 + lca.dis(y, a) + lca.dis(a, b);
        int t = lca.dis(a, y) + 1 + lca.dis(x, a) + lca.dis(a, b);

        bool ok = 0;
        for (int i : {p, q, r, s, t})
            ok |= (i <= k) and (((i ^ k) & 1) ^ 1);
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