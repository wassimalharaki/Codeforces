#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

// O(V + E)
bool is_cyclic(vector<vector<int>>& adj) {
    int n = adj.size();

    vector<char> c(n);
    auto dfs = [&](int u, auto&& dfs) -> bool {
        c[u] = 1;
        for (int& i : adj[u])
            if ((c[i] == 0 and dfs(i, dfs)) or c[i] == 1)
                return 1;
        c[u] = 2;
        return 0;
    };

    for (int i = 0; i < n; i++)
        if (c[i] == 0 and dfs(i, dfs))
            return 1;
    return 0;
}

// O(V + E)
vector<int> topsort(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<char> vis(n);
    vector<int> order;

    auto dfs = [&](int u, auto&& dfs) -> void {
        vis[u] = 1;
        for (int& i : adj[u])
            if (not vis[i])
                dfs(i, dfs);
        order.push_back(u);
    };

    for (int i = 0; i < n; i++)
        if (not vis[i]) dfs(i, dfs);
    reverse(order.begin(), order.end());

    return order;
}

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> adj(n);
    v<array<int, 3>> e;
    for (int i = 0; i < m; i++) {
        int t, a, b; cin >> t >> a >> b;
        --a, --b;
        if (t) adj[a].push_back(b);
        e.push_back({t, a, b});
    }

    if (is_cyclic(adj)) {
        cout << "NO" << nl;
        return;
    }

    v<int> in(n), order = topsort(adj);
    for (int i = 0; i < n; i++)
        in[order[i]] = i;

    cout << "YES" << nl;
    for (auto& [t, a, b] : e)
        if (t or in[a] < in[b])
            cout << a + 1 << " " << b + 1 << nl;
        else
            cout << b + 1 << " " << a + 1 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}