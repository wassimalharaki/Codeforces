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
    int n, k, c; cin >> n >> k >> c;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v<int> dp(n), next(n);
    auto dfs1 = [&](int u, int p, auto&& dfs) -> void {
        for (int& i : adj[u])
            if (i != p) {
                dfs(i, u, dfs);
                if (1 + dp[i] > dp[u]) {
                    next[u] = i;
                    dp[u] = 1 + dp[i];
                }
                else if (1 + dp[i] == dp[u])
                    next[u] = -1;
            }
    };
    dfs1(0, -1, dfs1);

    int ans = 0;
    auto dfs2 = [&](int u, int p, int x, auto&& dfs) -> void {
        ans = max(ans, dp[u] * k - x * c);

        v<int> dis;
        for (int& i : adj[u])
            if (i != p)
                dis.push_back(dp[i]);
        sort(dis.begin(), dis.end());

        for (int& i : adj[u])
            if (i != p) {
                if (next[u] == i) {
                    if (dis.size() > 1) {
                        int x = dis[dis.size() - 2];
                        if (x + 2 >= dp[i]) {
                            dp[i] = x + 2;
                            next[i] = -1;
                        }
                    }
                }
                else if (1 + dp[u] >= dp[i]) {
                        dp[i] = 1 + dp[u];
                        next[i] = -1;
                    }
                dfs(i, u, x + 1, dfs);
            }
    };
    dfs2(0, -1, 0, dfs2);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}