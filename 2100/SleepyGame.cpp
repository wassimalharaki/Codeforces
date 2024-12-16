#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        adj[i].resize(k);
        for (int& x : adj[i])
            cin >> x, x--;
        sort(adj[i].begin(), adj[i].end());
    }
    int src; cin >> src; src--;

    bool cyc = 0;
    v<array<int, 2>> vis(n), p(n), c(n);
    p[src][0] = -1;
    auto dfs = [&](int u, bool b, auto&& self) -> void {
        c[u][b] = 1, vis[u][b] = 1;

        for (int& i : adj[u]) {
            if (c[i][!b] == 1)
                cyc = 1;
            else  if (not vis[i][!b]) {
                p[i][!b] = u;
                self(i, !b, self);
            }
        }
        c[u][b] = 2;
    };
    dfs(src, 0, dfs);

    for (int i = 0; i < n; i++)
        if (adj[i].empty() and vis[i][1]) {
            v<int> ans;
            for (int u = i, b = 1; u != -1; u = p[u][b], b = !b)
                ans.push_back(u);
            reverse(ans.begin(), ans.end());

            cout << "Win" << nl;
            for (int& x : ans)
                cout << x + 1 << " ";
            cout << nl;
            return;
        }
    cout << (cyc ? "Draw" : "Lose") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}