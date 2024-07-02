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

// O(n), O(1)
struct DSU {
    vector<int> p;
    int comp;

    DSU(int n) {
        p.resize(n, -1); comp = n;
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
        comp--; return true;
    }
};

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> adj(n + 1);
    v<array<int, 3>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[i][0] = c, edges[i][1] = a, edges[i][2] = b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    sort(edges.rbegin(), edges.rend());

    DSU ds(n + 1);
    int min_index = -1;
    for (int i = 0; i < m; i++)
        if (not ds.merge(edges[i][1], edges[i][2]))
            min_index = i;
    
    int a = edges[min_index][1];
    int b = edges[min_index][2];
    int c = edges[min_index][0];

    v<int> vis(n + 1), parent(n + 1);
    auto dfs = [&](int u, auto&& dfs) -> void {
        vis[u] = 1;
        for (int& i : adj[u]) {
            if (vis[i]) continue;
            if (u == a and i == b) continue;
            parent[i] = u;
            dfs(i, dfs);
        }
    };
    dfs(a, dfs);

    v<int> ans;
    while (b != 0) {
        ans.push_back(b);
        b = parent[b];
    }

    cout << c << " " << ans.size() << nl;
    for (int& a : ans)
        cout << a << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}