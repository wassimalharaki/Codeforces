#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

// O(n), O(1)
struct DSU {
    vector<int> p;

    DSU(int n) {
        p.resize(n, -1);
    }

    int find(int x) {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }

    int size(int x) {
        return - p[find(x)];
    }

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

// O(nlog(n))
vector<array<int, 3>> kruskal(int n, vector<array<int, 3>>& edges) {
    sort(edges.begin(), edges.end());

    vector<array<int, 3>> tree(n - 1);
    DSU ds(n);
    int cost = 0, j = 0;
    for (int i = 0; j < n - 1 and i < edges.size(); i++) {
        int a = edges[i][1], b = edges[i][2];
        if (not ds.merge(a, b)) continue;
        tree[j][1] = a; tree[j][2] = b; tree[j][0] = edges[i][0];
        cost += edges[i][0];
        j++;
    }
    return tree;
}

void solve() {
    int n; cin >> n;

    v<v<int>> a(n, v<int>(n));
    for (auto& x : a)
        for (auto& y : x)
            cin >> y;

    v<array<int, 3>> e;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            e.push_back({a[i][j], i, j});
    e = kruskal(n, e);

    v<v<array<int, 2>>> adj(n);
    for (auto& [c, x, y] : e) {
        if (c == 0) {
            cout << "NO" << nl;
            return;
        }
        adj[x].push_back({y, c});
        adj[y].push_back({x, c});
    }
    
    int rt;
    v dist(n, v<int>(n));
    auto dfs = [&](int u, int p, int d, auto&& dfs) -> void {
        dist[rt][u] = d;
        for (auto& [i, c] : adj[u])
            if (i != p)
                dfs(i, u, d + c, dfs);
    };

    for (rt = 0; rt < n; rt++)
        dfs(rt, -1, 0, dfs);

    cout << (a == dist ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}