#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

// O(nlog(n)), O(1)
struct LCA {
    using ai2 = array<int, 2>;
    vector<int> in;
    vector<vector<ai2>> d;

    LCA(vector<vector<int>>& adj, int root = 0) {
        in.resize(adj.size());

        vector<ai2> path;
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

    void build(vector<ai2>& a) {
        int n = a.size(), k = 64 - __builtin_clzll(n);
        d.resize(k, vector<ai2>(n));
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
    int n; cin >> n;

    v<v<int>> adj(n);
    v<v<array<int, 2>>> adj_in(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        adj_in[a].push_back({b, i});
        adj_in[b].push_back({a, i});
    }
    LCA lca(adj);

    v<int> diff(n);
    int k; cin >> k;
    while (k--) {
        int a, b; cin >> a >> b;
        int c = lca.prod(--a, --b);
        if (c == a)
            diff[c]--, diff[b]++;
        else if (c == b)
            diff[c]--, diff[a]++;
        else
            diff[c] -= 2, diff[a]++, diff[b]++;
    }

    v<int> ans(n - 1);
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        for (int& i : adj[u])
            if (i != p)
                dfs(i, u, dfs);

        for (auto& [i, j] : adj_in[u])
            if (i != p) {
                ans[j] += diff[i];
                diff[u] += diff[i];
            }
    };
    dfs(0, -1, dfs);

    for (int& x : ans)
        cout << x << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}