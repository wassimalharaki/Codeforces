#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    v<v<array<int, 3>>> adj(n);
    v<array<int, 3>> e(m);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        e[i] = {--a, --b, !c};
        adj[a].push_back({b, !c, i});
        adj[b].push_back({a, !c, i});
    }

    using ai2 = array<int, 2>;
    v<int> vis(n);
    v<ai2> d(n, {INT_MAX, INT_MAX});
    v<ai2> p(n, {-1, -1});

    using ai3 = array<int, 3>;
    priority_queue<ai3, v<ai3>, greater<ai3>> pq;
    pq.push({0, 0, 0});
    d[0] = {0, 0};

    while (pq.size()) {
        auto [w, b, u] = pq.top();
        pq.pop();

        if (vis[u]) continue;
        vis[u] = 1;

        for (auto& [i, c, j] : adj[u])
            if ((w + 1 < d[i][0]) or (w + 1 == d[i][0] and b + c < d[i][1])) {
                d[i][0] = w + 1;
                d[i][1] = b + c;
                p[i] = {u, j};
                pq.push({d[i][0], d[i][1], i});
            }
    }

    v<int> use(m);
    for (int u = n - 1; u; u = p[u][0])
        use[p[u][1]] = 1;

    v<ai3> ans;
    for (int i = 0; i < m; i++)
        if ((use[i] and e[i][2]) or (not use[i] and not e[i][2]))
            ans.push_back({e[i][0] + 1, e[i][1] + 1, e[i][2]});

    cout << ans.size() << nl;
    for (auto& [a, b, c] : ans)
        cout << a << " " << b << " " << c << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}