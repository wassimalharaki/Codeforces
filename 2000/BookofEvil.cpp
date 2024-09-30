#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m, k; cin >> n >> m >> k;

    v<int> a(m);
    for (int& x : a)
        cin >> x, x--;
    
    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    v<int> dis(n);
    auto dfs1 = [&](int u, int p, int d, auto&& dfs) -> void {
        dis[u] = d;
        for (int& i : adj[u])
            if (i != p)
                dfs(i, u, d + 1, dfs);
    };
    dfs1(a[0], -1, 0, dfs1);
    int y = a[0];
    for (int& x : a)
        if (dis[x] > dis[y])
            y = x;
    dfs1(y, -1, 0, dfs1);
    int z = y;
    for (int& x : a)
        if (dis[x] > dis[z])
            z = x;
    v<int> cnt(n);
    auto dfs2 = [&](int u, int p, int d, auto&& dfs) -> void {
        if (d > k) return;
        cnt[u]++;
        for (int& i : adj[u])
            if (i != p)
                dfs(i, u, d + 1, dfs);
    };
    dfs2(y, -1, 0, dfs2);
    dfs2(z, -1, 0, dfs2);

    int ans = 0;
    for (int& x : cnt)
        ans += x == 2;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}