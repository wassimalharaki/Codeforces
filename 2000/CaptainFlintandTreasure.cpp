#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

// O(V + E)
vector<int> topsort(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<char> vis(n);
    vector<int> order;

    auto dfs = [&](int u, auto&& dfs) -> void {
        vis[u] = 1;
        for (int& i : adj[u])
            if (not vis[i])
                dfs(i, dfs);
        order.push_back(u);
    };

    for (int i = 0; i < n; i++)
        if (not vis[i]) dfs(i, dfs);
    reverse(order.begin(), order.end());

    return order;
}

void solve() {
    int n; cin >> n;

    v<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x, x--;

    v<v<int>> adj(n);
    for (int i = 0; i < n; i++)
        if (b[i] != -2)
            adj[i].push_back(b[i]);
    auto ts = topsort(adj);
    
    int ans = 0;
    v<int> ord;
    for (int& u : ts)
        if (a[u] >= 0) {
            ans += a[u];
            if (adj[u].size())
                a[adj[u][0]] += a[u];
            ord.push_back(u);
        }
    reverse(ts.begin(), ts.end());
    for (int& u : ts)
        if (a[u] < 0) {
            ans += a[u];
            if (adj[u].size())
                a[adj[u][0]] += a[u];
            ord.push_back(u);
        }
    
    cout << ans << nl;
    for (int& x : ord)
        cout << x + 1 << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}