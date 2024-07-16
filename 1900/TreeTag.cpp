#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    --a, --b;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    v<int> dist(n);
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        for (int& i : adj[u])
            if (i != p) {
                dist[i] = dist[u] + 1;
                dfs(i, u, dfs);
            }
    };
    dfs(b, -1, dfs);
    
    if (dist[a] <= da) {
        cout << "Alice" << nl;
        return;
    }

    int u = max_element(dist.begin(), dist.end()) - dist.begin();
    fill(dist.begin(), dist.end(), 0ll);
    dfs(u, -1, dfs);
    int mxD = *max_element(dist.begin(), dist.end());
    da = min(da, mxD), db = min(db, mxD);

    cout << (db > 2 * da ? "Bob" : "Alice") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}