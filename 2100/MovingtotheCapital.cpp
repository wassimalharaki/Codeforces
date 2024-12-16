#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

// O(V + E)
vector<int> topsort(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<char> vis(n);
    vector<int> order;

    auto dfs = [&](int u, auto&& dfs) -> void {
        vis[u] = 1;
        for (const int& i : adj[u])
            if (not vis[i])
                dfs(i, dfs);
        order.push_back(u);
    };

    for (int i = 0; i < n; i++)
        if (not vis[i]) dfs(i, dfs);
    // reverse(order.begin(), order.end());

    return order;
}

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a - 1].push_back(b - 1);
    }

    v<int> d(n, 1e9);
    queue<int> q;
    q.push(0); d[0] = 0;
    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int& i : adj[u])
            if (d[u] + 1 < d[i]) {
                d[i] = d[u] + 1;
                q.push(i);
            }
    }

    v<v<int>> fwd(n), bwd(n);
    for (int u = 0; u < n; u++)
        for (int& i : adj[u])
            if (d[u] < d[i])
                fwd[u].push_back(i);
            else
                bwd[u].push_back(i);
    
    v<int> ans(n);
    for (int& u : topsort(fwd)) {
        ans[u] = d[u];
        for (int& i : fwd[u])
            ans[u] = min(ans[u], ans[i]);
        for (int& i : bwd[u])
            ans[u] = min(ans[u], d[i]);
    }
    for (int& x : ans)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}