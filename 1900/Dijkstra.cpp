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

void solve() {
    int n, m; cin >> n >> m;

    v<v<array<int, 2>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    v<int> p(n, -1), d(n, LLONG_MAX), vis(n);
    priority_queue<ai2, v<ai2>, greater<ai2>> pq;
    pq.push({0, 0});
    p[0] = -2, d[0] = 0;

    while (pq.size()) {
        auto [w, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;

        for (auto& [i, c] : adj[u])
            if (w + c < d[i]) {
                p[i] = u;
                d[i] = w + c;
                pq.push({d[i], i});
            }
    }

    if (p[n - 1] == -1)
        cout << -1 << nl;
    else {
        v<int> ans;
        for (int u = n - 1; u != -2; u = p[u])
            ans.push_back(u);
        reverse(ans.begin(), ans.end());

        for (int& x : ans)
            cout << x + 1 << " ";
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}