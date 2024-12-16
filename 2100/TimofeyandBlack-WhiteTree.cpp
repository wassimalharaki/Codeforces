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

    LCA(const vector<vector<int>>& adj, int root = 0) {
        in.resize(adj.size());
        dep.resize(adj.size());

        vector<ai2> path;
        auto dfs = [&](int u, int p, auto&& self) -> void {
            in[u] = path.size();
            dep[u] = p == -1 ? 0 : dep[p] + 1;
            path.push_back({u, dep[u]});

            for (const int& i : adj[u])
                if (i != p) {
                    self(i, u, self);
                    path.push_back({u, dep[u]});
                }
        };
        dfs(root, -1, dfs);
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

    int dist(int a, int b) {
        return dep[a] + dep[b] - 2 * dep[prod(a, b)];
    }
};

vector<int> centroid_decomp(const vector<vector<int>>& adj) {
    vector<int> sz(adj.size()), par(adj.size()), dead(adj.size());

    auto find_size = [&](int u, int p, auto&& self) -> int {
        sz[u] = 1;
        for (const int& i : adj[u])
            if (i != p and not dead[i])
                sz[u] += self(i, u, self);
        return sz[u];
    };

    auto find_centroid = [&](int u, int p, int n, auto&& self) -> int {
        for (const int& i : adj[u])
            if (i != p and not dead[i] and sz[i] > n / 2)
                return self(i, u, n, self);
        return u;
    };

    auto build = [&](int u, int p, auto&& self) -> void {
        int n = find_size(u, p, find_size);
        int cent = find_centroid(u, p, n, find_centroid);
        par[cent] = p;
        dead[cent] = 1;

        for (const int& i : adj[cent])
            if (i != p and not dead[i])
                self(i, cent, self);
    };
    build(0, -1, build);
    return par;
}

void solve() {
    int n, rt; cin >> n >> rt; rt--;

    v<int> a(n - 1);
    for (int& x : a) cin >> x, x--;
    
    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    LCA lca(adj);
    v<int> p = centroid_decomp(adj);
    
    int ans = 1e9;
    v<int> dp(n, 1e9);
    for (int u : {rt}) {
        for (int i = u; i != -1; i = p[i]) {
            ans = min(ans, dp[i] + lca.dist(u, i));
            dp[i] = min(dp[i], lca.dist(u, i));
        }
    }
    for (int& u : a) {
        for (int i = u; i != -1; i = p[i]) {
            ans = min(ans, dp[i] + lca.dist(u, i));
            dp[i] = min(dp[i], lca.dist(u, i));
        }
        cout << ans << " ";
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}