#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

// O(V + E)
bool is_cyclic(const vector<vector<array<int, 2>>>& adj) {
    int n = adj.size();

    vector<char> c(n);
    auto dfs = [&](int u, auto&& dfs) -> bool {
        c[u] = 1;
        for (const auto& [i, _] : adj[u])
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

void solve() {
    int n, m; cin >> n >> m;

    v<v<array<int, 2>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a - 1].push_back({b - 1, i});
    }

    if (not is_cyclic(adj)) {
        cout << 1 << nl;
        for (int i = 0; i < m; i++)
            cout << 1 << " ";
        cout << nl;
        return;
    }

    v<int> vis(n), ans(m);
    auto dfs = [&](int u, auto&& self) -> void {
        if (vis[u]) return;
        vis[u] = 2;
        for (auto& [i, j] : adj[u]) {
            ans[j] = vis[i] == 2;
            self(i, self);
        }
        vis[u] = 1;
    };
    for (int i = 0; i < n; i++)
        dfs(i, dfs);

    cout << 2 << nl;
    for (int& x : ans)
        cout << x + 1 << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}