#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

// O(V + E)
vector<int> comp, comps;
void tarjan(const vector<vector<int>>& adj) {
    int n = adj.size(), curr = 0;
    comps.clear();
    comp.assign(n, -1);
    vector<int> disc(n), vis;

    auto dfs = [&](int u, int p, auto&& dfs) -> int {
        int low = disc[u] = ++curr;
        vis.push_back(u);

        for (const int& i : adj[u])
            if (i != p and comp[i] == -1)
                low = min(low, disc[i] ?: dfs(i, u, dfs));

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
        if (not disc[i]) dfs(i, -1, dfs);
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

    int k = 0;
    v<int> id(n);
    for (int& u : comps)
        id[u] = k++;
    for (int& u : comp)
        u = id[u];
    v<v<int>> tree(k);
    for (int u = 0; u < n; u++)
        for (int& i : adj[u])
            if (comp[i] != comp[u])
                tree[comp[u]].push_back(comp[i]);
    for (auto& x : tree) {
        sort(x.begin(), x.end());
        unique(x.begin(), x.end());
    }

    v<int> dis(k);
    auto dfs = [&](int u, int p, auto&& self) -> void {
        dis[u] = p == -1 ? 0 : dis[p] + 1;
        for (int& i : tree[u])
            if (i != p)
                self(i, u, self);
    };
    dfs(0, -1, dfs);
    dfs(max_element(dis.begin(), dis.end()) - dis.begin(), -1, dfs);
    cout << *max_element(dis.begin(), dis.end()) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}