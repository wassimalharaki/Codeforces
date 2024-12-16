#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    a--, b--, c--;

    v<int> p(m);
    for (int& x : p) cin >> x;
    sort(p.begin(), p.end());
    v<int> pref(m + 1);
    partial_sum(p.begin(), p.end(), pref.begin() + 1);

    v<v<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    auto bfs = [&](int src) -> v<int> {
        v<int> d(n, 1e9); d[src] = 0;
        queue<int> q; q.push(src);

        while (q.size()) {
            int u = q.front();
            q.pop();

            for (int& i : adj[u])
                if (d[i] > d[u] + 1) {
                    d[i] = d[u] + 1;
                    q.push(i);
            }
        }
        return d;
    };

    auto da = bfs(a), db = bfs(b), dc = bfs(c);
    int ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        int x = db[i], y = da[i], z = dc[i];
        if (x + y + z > m) continue;
        ans = min(ans, 2 * pref[x] + pref[y + x] - pref[x] + pref[x + y + z] - pref[x + y]);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}