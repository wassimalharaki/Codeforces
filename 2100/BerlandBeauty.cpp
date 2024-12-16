#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<v<array<int, 2>>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }

    v<array<int, 2>> p(n);
    v<int> d(n);
    auto dfs = [&](int u, int par, auto&& self) -> void {
        d[u] = par != -1 ? d[par] + 1 : 0;
        for (auto& [i, j] : adj[u])
            if (i != par) {
                p[i] = {u, j};
                self(i, u, self);
            }
    };
    dfs(0, -1, dfs);

    v<int> ans(n - 1, 1);
    int m; cin >> m;
    v<array<int, 3>> q(m);
    for (auto& [a, b, x] : q)
        cin >> a >> b >> x, a--, b--;

    for (auto [a, b, x] : q)
        while (a != b) {
            if (d[a] < d[b]) swap(a, b);
            ans[p[a][1]] = max(ans[p[a][1]], x);
            a = p[a][0];
        }

    for (auto [a, b, x] : q) {
        int y = INT_MAX;
        while (a != b) {
            if (d[a] < d[b]) swap(a, b);
            y = min(y, ans[p[a][1]]);
            a = p[a][0];
        }
        if (y != x)
            return void(cout << -1 << nl);
    }

    for (int& x : ans)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}