#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];
    
    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    {
        auto dfs = [&](int u, int p, auto&& dfs) -> void {
            if (u)
                adj[u].erase(find(adj[u].begin(), adj[u].end(), p));
            for (int& i : adj[u])
                dfs(i, u, dfs);
        };
        dfs(0, -1, dfs);
    }
    
    int zb = count(b.begin(), b.end(), 0);
    int zc = count(c.begin(), c.end(), 0);
    if (zb != zc) {
        cout << -1 << nl;
        return;
    }

    v<array<int, 2>> d(n);
    for (int i = 0; i < n; i++)
        d[i] = {a[i], i};
    sort(d.begin(), d.end());

    v<int> e(n);
    for (int i = 0; i < n; i++)
        e[i] = d[i][1];

    v<array<int, 2>> dp(n, {-1, -1});
    auto dfs = [&](int u, auto&& dfs) -> void {
        if (dp[u] != array<int, 2>{-1, -1})
            return;
        dp[u] = {0, 0};
        if (b[u] != c[u])
            dp[u][c[u]]++;

        for (int& i : adj[u]) {
            dfs(i, dfs);
            dp[u][0] += dp[i][0];
            dp[u][1] += dp[i][1];
        }
    };

    int ans = 0;
    for (int& u : e) 
        if (dp[u] == array<int, 2>{-1, -1}) {
            dfs(u, dfs);
            int sub = min(dp[u][0], dp[u][1]);
            ans += a[u] * sub * 2;
            dp[u][0] -= sub, dp[u][1] -= sub;
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