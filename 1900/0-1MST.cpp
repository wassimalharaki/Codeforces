#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (auto& x : adj) {
        x.push_back(-1);
        x.push_back(n);
        sort(x.begin(), x.end());
    }
    
    set<int> alive;
    for (int i = 0; i < n; i++)
        alive.insert(i);

    int ans = -1;
    auto dfs = [&](int u, auto&& dfs) -> void {
        for (int i = 1; i < adj[u].size(); i++) {
            int x = adj[u][i - 1], y = adj[u][i];

            v<int> can;
            auto it = alive.upper_bound(x);
            while (it != alive.end() and *it < y)
                can.push_back(*it++);

            for (int& j : can)
                alive.erase(j);

            for (int& j : can)
                dfs(j, dfs);
        }
    };
    for (int i = 0; i < n; i++)
        if (alive.count(i)) {
            ans++, dfs(i, dfs);
            alive.erase(i);
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