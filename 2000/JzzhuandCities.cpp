#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

using ai2 = array<int, 2>;

void solve() {
    int n, m, k; cin >> n >> m >> k;

    v<v<ai2>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        --a, --b;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int ans = 0;
    v<int> t(n);
    for (int i = 0; i < k; i++) {
        int a, c; cin >> a >> c;
        if (t[--a]) {
            ans++;
            if (t[a] > c)
                t[a] = c;
        }
        else t[a] = c;
    }

    v<int> use(n), vis(n), dis(n, 1e18);
    priority_queue<ai2, v<ai2> ,greater<ai2>> pq;
    dis[0] = 0; pq.push({0, 0});

    for (int i = 0; i < n; i++)
        if (t[i]) {
            dis[i] = t[i], use[i] = 1;
            pq.push({dis[i], i});
        }

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;

        for (auto [i, c] : adj[u]) {
            c += d;
            if (c < dis[i]) {
                if (use[i])
                    use[i] = 0, ans++;
                dis[i] = c;
                pq.push({c, i});
            }
            else if (c == dis[i] and use[i])
                use[i] = 0, ans++;
        }
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