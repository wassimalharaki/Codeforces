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

using ai2 = array<int, 2>;
using ai3 = array<int, 3>;

void solve() {
    int n, m; cin >> n >> m;

    v<v<ai2>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<v<int>> dist(n, v<int>(1e3 + 1, LLONG_MAX));
    dist[0][a[0]] = 0;
    priority_queue<ai3, v<ai3>, greater<ai3>> pq;
    pq.push({0, a[0], 0});

    while (pq.size()) {
        auto [w, c, u] = pq.top();
        pq.pop();

        if (w > dist[u][c]) continue;

        for (auto [i, k] : adj[u]) {
            int s = min(a[i], c), d = w + k * c;
            if (d < dist[i][s]) {
                dist[i][s] = d;
                pq.push({d, s, i});
            }
        }
    }
    
    int ans = LLONG_MAX;
    for (int& x : dist[n - 1])
        ans = min(ans, x);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}