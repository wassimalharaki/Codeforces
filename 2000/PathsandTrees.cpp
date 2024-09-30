#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

using ai2 = array<int, 2>;
using ai3 = array<int, 3>;

void solve() {
    int n, m; cin >> n >> m;

    v<int> e(m + 1); e[m] = LLONG_MAX;
    v<v<ai3>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b, c, i});
        adj[b].push_back({a, c, i});
        e[i] = c;
    }
    int src; cin >> src; src--;

    v<int> vis(n);
    v<ai2> dis(n, ai2{LLONG_MAX, m});
    priority_queue<ai2, v<ai2>, greater<ai2>> pq;
    dis[src] = {0, 0};
    pq.push({0, src});

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;

        for (auto& [i, c, j] : adj[u]) {
            if (d + c < dis[i][0]) {
                dis[i][0] = d + c;
                dis[i][1] = j;
                pq.push({dis[i][0], i});
            }
            else if (d + c == dis[i][0])
                dis[i][1] = e[j] < e[dis[i][1]] ? j : dis[i][1];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (i != src)
            ans += e[dis[i][1]];
    cout << ans << nl;
    for (int i = 0; i < n; i++)
        if (i != src)
            cout << dis[i][1] + 1 << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}