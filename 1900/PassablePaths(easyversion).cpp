#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

// O(nlog(n)), O(1)
struct LCA {
    using ai2 = array<int, 2>;
    vector<int> in, depth;
    vector<vector<ai2>> d;

    LCA(vector<vector<int>>& adj, int root = 0) {
        in.resize(adj.size());
        depth.resize(adj.size());

        vector<ai2> path;
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
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    LCA lca(adj);

    int q; cin >> q;
    v<int> here(n);
    v<int> d_cnt(n);
    while (q--) {
        int k; cin >> k;
        v<array<int, 2>> a(k);
        bool depth_check = 1;
        for (auto& [d, u] : a) {
            cin >> u;
            d = lca.depth[--u];
            depth_check &= ++d_cnt[d] <= 2;
            here[u] = 1;
        }

        if (not depth_check) {
            for (auto& [d, u] : a)
                here[u] = 0, d_cnt[d] = 0;
            cout << "NO" << nl;
            continue;
        }
        sort(a.rbegin(), a.rend());

        {
            bool ok = 1;
            for (int i = 0; i < k - 1; i++)
                ok &= (lca.prod(a[i][1], a[i + 1][1]) == a[i + 1][1]);
            if (ok) {
                for (auto& [d, u] : a)
                    here[u] = 0, d_cnt[d] = 0;
                cout << "YES" << nl;
                continue;
            }
        }

        int p = -1;
        bool ok = 1;
        for (int i = 0; i < k - 1; i++) {
            int c = lca.prod(a[i][1], a[i + 1][1]);
            if (c == a[i + 1][1]) continue;
            if (p != -1 and p != c)
                ok = 0;
            if (a.back()[0] < lca.depth[c])
                ok = 0;
            p = c;
        }

        v<int> left, right;
        left.push_back(a[0][1]);
        int j = -1;
        for (int i = 1; i < k; i++)
            if (lca.prod(a[i][1], left.back()) == a[i][1])
                left.push_back(a[i][1]);
            else if (right.empty()) {
                right.push_back(a[i][1]);
                j = i;
            }
        
        for (int i = j + 1; i < k; i++)
            if (lca.prod(a[i][1], right.back()) == a[i][1])
                right.push_back(a[i][1]);
        
        int sz = left.size() + right.size();
        ok &= sz == k + (left.back() == right.back());
        
        cout << (ok ? "YES" : "NO") << nl;
        for (auto& [d, u] : a)
            here[u] = 0, d_cnt[d] = 0;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}