#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

bool check(v<v<array<int, 2>>>& adj, v<int>& vis, v<int>& ans) {
    int n = adj.size();

    v<array<int, 2>> path;
    auto dfs = [&](int u, int z, auto&& dfs) -> void {
        vis[u] = 1;
        path.push_back({u, z});
        for (auto& [i, _] : adj[u])
            if (not vis[i]) {
                if (z == -1)
                    path.back()[1] = _;
                dfs(i, (z == -1 ? _ : -1), dfs);
            }
    };

    for (int i = 0; i < n; i++) {
        int alive = 0;
        for (auto& [u, _] : adj[i])
            if (not vis[u])
                alive++;
        if (alive == 2 or vis[i]) continue;

        path.clear();
        dfs(i, -1, dfs);
        if (path.size() & 1) return 0;

        for (auto& [u, b] : path)
            ans[u] = b;
    }
    return *min_element(vis.begin(), vis.end());
}

void solve() {
    int n, x, y; cin >> n >> x >> y;

    v<array<int, 2>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i][0], a[i][1] = i;
    sort(a.begin(), a.end());

    v<v<array<int, 2>>> adj(n);
    v<array<int, 2>> dbl;
    v<int> vis(n), ans(n);

    for (auto& [z, i] : a) {
        if (2 * z == x or 2 * z == y)
            dbl.push_back({z, i});
        auto it = lower_bound(a.begin(), a.end(), array{x - z, -1});
        if (it != a.end() and (*it)[0] == x - z and 2 * z != x)
            adj[i].push_back({(*it)[1], 0});
        it = lower_bound(a.begin(), a.end(), array{y - z, -1});
        if (it != a.end() and (*it)[0] == y - z and 2 * z != y and x != y)
            adj[i].push_back({(*it)[1], 1});
    }

    int m = dbl.size();
    for (int mask = 0; mask < 1 << m; mask++) {
        fill(vis.begin(), vis.end(), 0);
        for (int i = 0; i < m; i++)
            if ((1 << i) & mask) {
                vis[dbl[i][1]] = 1;
                ans[dbl[i][1]] = 2 * dbl[i][0] == y;
            }
        if (check(adj, vis, ans)) {
            cout << "YES" << nl;
            for (int& z : ans)
                cout << z << " ";
            cout << nl;
            return;
        }
    }
    cout << "NO" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}