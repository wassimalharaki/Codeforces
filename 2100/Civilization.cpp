#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

// O(n), O(1)
struct DSU {
    vector<int> p;

    DSU(int n) { p.resize(n, -1); }

    int find(int x) {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }

    int size(int x) { return - p[find(x)]; }

    bool same_set(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (p[x] > p[y]) swap(x, y);
        p[x] += p[y]; p[y] = x;
        return true;
    }
};

void solve() {
    int n, m, q; cin >> n >> m >> q;

    v<v<int>> adj(n);
    DSU ds(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        ds.merge(--a, --b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v<int> d(n), comp;
    auto dfs = [&](int u, int p, auto&& self) -> void {
        d[u] = p == -1 ? 0 : d[p] + 1;
        comp.push_back(u);
        for (int& i : adj[u])
            if (i != p) self(i, u, self);
    };

    v<int> dp(n);
    for (int i = 0; i < n; i++)
        if (ds.find(i) == i) {
            dfs(i, -1, dfs);
            int a = i;
            for (int& u : comp)
                if (d[u] > d[a])
                    a = u;
            comp.clear();

            dfs(a, -1, dfs);
            int x = 0;
            for (int& u : comp)
                x = max(x, d[u]);
            dp[i] = x;
            comp.clear();
        }

    while (q--) {
        int c; cin >> c;
        if (c == 1) {
            int x; cin >> x;
            cout << dp[ds.find(--x)] << nl;
        }
        else {
            int x, y; cin >> x >> y;
            if (ds.same_set(--x, --y)) continue;
            x = ds.find(x); y = ds.find(y);
            ds.merge(x, y);

            int mx = max(dp[x], dp[y]);
            int mn = min(dp[x], dp[y]);

            dp[ds.find(x)] = max(mx, (mx + 1) / 2 + (mn + 1) / 2 + 1);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}