#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

// O(V + E)
vector<int> comp, comps;
void tarjan(vector<vector<int>>& adj) {
    int n = adj.size(), curr = 0;
    comps.clear();
    comp.assign(n, -1);
    vector<int> disc(n), vis;

    auto dfs = [&](int u, int p, auto&& dfs) -> int {
        int low = disc[u] = ++curr;
        vis.push_back(u);

        for (int& i : adj[u])
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
        if (!disc[i]) dfs(i, -1, dfs);
    reverse(comps.begin(), comps.end());
}

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> adj(n);
    v<array<int, 2>> e(m);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        e[i] = {a, b};
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    tarjan(adj);

    if (comps.size() > 1) {
        cout << 0 << nl;
        return;
    }

    v<v<array<int, 2>>> d_adj(n);
    for (int i = 0; i < m; i++) {
        d_adj[e[i][0]].push_back({e[i][1], i});
        d_adj[e[i][1]].push_back({e[i][0], i});
    }

    v<int> vis(n), dead(m);
    auto dfs = [&](int u, auto&& dfs) -> void {
        vis[u] = 1;
        for (auto& [i, j] : d_adj[u])
            if (vis[i]) {
                if (not dead[j])
                    cout << u + 1 << " " << i + 1 << nl;
                dead[j] = 1;
            }
            else {
                dead[j] = 1;
                cout << u + 1 << " " << i + 1 << nl;
                dfs(i, dfs);
            }
    };
    dfs(0, dfs);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}