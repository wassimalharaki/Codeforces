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
    int n, c; cin >> n >> c;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v<array<int, 2>> dp(n);
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        dp[u][1] = a[u];
        for (int& i : adj[u])
            if (i != p) {
                dfs(i, u, dfs);
                dp[u][0] += max(dp[i][0], dp[i][1]);
                dp[u][1] += max(dp[i][0], dp[i][1] - 2 * c);
            }
    };
    dfs(0, -1, dfs);
    cout << max(dp[0][0], dp[0][1]) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}