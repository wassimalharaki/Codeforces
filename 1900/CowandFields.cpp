#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m, k; cin >> n >> m >> k;

    v<int> a(k);
    for (int& x : a) cin >> x, x--;

    v<v<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    auto bfs = [&](int u) -> v<int> {
        queue<int> q;
        v<int> dis(n, 1e6);
        dis[u] = 0;
        q.push(u);

        while (q.size()) {
            u = q.front();
            q.pop();

            for (int& i : adj[u])
                if (dis[i] > dis[u] + 1) {
                    dis[i] = dis[u] + 1;
                    q.push(i);
                }
        }
        return dis;
    };

    v<int> front = bfs(0);
    v<int> back = bfs(n - 1);

    v<array<int, 2>> b(k);
    for (int i = 0; i < k; i++)
        b[i] = {front[a[i]], a[i]};
    sort(b.begin(), b.end());

    int ans = 0;
    for (int i = 1; i < k; i++) {
        int fwd_d = b[i - 1][0] + 1;
        int bwd_d = back[b[i][1]];
        ans = max(ans, fwd_d + bwd_d);
    }
    cout << min(ans, front[n - 1]) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}