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

// O(V + E)
v<int> comp, comps;
void tarjan(v<v<int>>& adj) {
    int n = adj.size(), curr = 0;
    comps.clear();
    comp.assign(n, -1);
    v<int> disc(n), vis;

    auto dfs = [&](int u, auto&& dfs) -> int {
        int low = disc[u] = ++curr;
        vis.push_back(u);

        for (int& i : adj[u])
            if (comp[i] == -1)
                low = min(low, disc[i] ?: dfs(i, dfs));

        if (low == disc[u]) {
            comps.push_back(u);
            for (int i = -1; i != u;) {
                i = vis.back();
                comp[i] = u;
                vis.pop_back();
            }
        }
        return low;
    };

    for (int i = 0; i < n; i++)
        if (!disc[i]) dfs(i, dfs);
    reverse(comps.begin(), comps.end());
}

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    tarjan(adj);

    v<int> comp_size(n);
    v<v<int>> adj_tree(n);
    for (int u = 0; u < n; u++) {
        comp_size[comp[u]]++;
        for (int i : adj[u]) {
            i = comp[i];
            adj_tree[comp[u]].push_back(i);
            adj_tree[i].push_back(comp[u]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        sort(adj_tree[i].begin(), adj_tree[i].end());
        adj_tree[i].resize(unique(adj_tree[i].begin(), adj_tree[i].end()) - adj_tree[i].begin());
    }

    int ans = n * (n - 1) / 2;
    v<int> cnt(n);
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        cnt[u] += comp_size[u];
        for (int i : adj_tree[u])
            if (i != p and i != u) {
                dfs(i, u, dfs);
                cnt[u] += cnt[i];
            }
        for (int i : adj_tree[u])
            if (i != p and i != u) {
                int down = cnt[i], up = n - cnt[i];
                ans = min(ans, down * (down - 1) / 2 + up * (up - 1) / 2);
            }
    };
    dfs(comps[0], -1, dfs);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}