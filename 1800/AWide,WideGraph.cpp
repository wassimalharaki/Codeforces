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

void solve() {
    int n; cin >> n;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    v<int> dist(n);
    auto dfs = [&](int u, int p, int d, auto&& dfs) -> void {
        dist[u] = d;

        for (int& i : adj[u])
            if (i != p)
                dfs(i, u, d + 1, dfs);
    };
    dfs(0, -1, 0, dfs);

    int u = max_element(dist.begin(), dist.end()) - dist.begin();
    fill(dist.begin(), dist.end(), 0ll);
    dfs(u, -1, 0, dfs);

    v<v<int>> d1(n);
    for (int i = 0; i < n; i++)
        d1[dist[i]].push_back(i);
    
    u = max_element(dist.begin(), dist.end()) - dist.begin();
    fill(dist.begin(), dist.end(), 0ll);
    dfs(u, -1, 0, dfs);

    v<v<int>> d2(n);
    for (int i = 0; i < n; i++)
        d2[dist[i]].push_back(i);

    v<int> ans(n + 1, n), dead(n);
    for (int i = n - 1; i > 0; i--) {
        ans[i] = ans[i + 1];
        for (int& u : d1[i])
            if (not dead[u]) {
                dead[u] = 1;
                ans[i]--;
            }
        for (int& u : d2[i])
            if (not dead[u]) {
                dead[u] = 1;
                ans[i]--;
            }
        if (ans[i] != n and ans[i + 1] == n)
            ans[i]++;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}