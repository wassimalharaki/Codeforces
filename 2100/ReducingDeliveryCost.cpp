#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

using ai2 = array<int, 2>;
// O(Elog(V))
vector<int> dijkstra(int src, const vector<vector<ai2>>& adj) {
    int n = adj.size();
    vector<int> d(n, INT_MAX);
    vector<char> vis(n);
    priority_queue<ai2, vector<ai2>, greater<ai2>> pq;

    d[src] = 0;
    pq.push({0, src});

    while (pq.size()) {
        auto [w, u] = pq.top();
        pq.pop();

        if (vis[u]) continue;
        vis[u] = 1;

        for (const auto& [i, c] : adj[u])
            if (w + c < d[i]) {
                d[i] = w + c;
                pq.push({d[i], i});
            }
    }
    return d;
}

void solve() {
    int n, m, k; cin >> n >> m >> k;

    v<array<int, 3>> e(m);
    v<v<ai2>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        e[i] = {--a, --b, c};
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    v<ai2> q(k);
    for (auto& [a, b] : q)
        cin >> a >> b, a--, b--;

    v<v<int>> d(n);
    for (int i = 0; i < n; i++)
        d[i] = dijkstra(i, adj);

    int ans = LLONG_MAX;
    for (auto& [a, b, c] : e) {
        int curr = 0;
        for (auto& [x, y] : q)
            curr += min({d[x][y], d[x][a] + d[b][y], d[x][b] + d[a][y]});
        ans = min(ans, curr);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}