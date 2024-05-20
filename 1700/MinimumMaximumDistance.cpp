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
    int n, k; cin >> n >> k;

    v<int> flag(n);
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        flag[x - 1] = 1;
    }

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v<array<int, 2>> dp(n, {INT_MIN, INT_MIN}), next(n, {-1, -1});
    auto dfs1 = [&](int u, int p, auto&& dfs) -> void {
        if (flag[u]) dp[u] = {0, 0};
        
        for (int& i : adj[u])
            if (i != p) {
                dfs(i, u, dfs);
                auto [x, y] = dp[i];
                if (1 + x > dp[u][0]) {
                    swap(dp[u][0], dp[u][1]);
                    swap(next[u][0], next[u][1]);
                    dp[u][0] = 1 + x;
                    next[u][0] = i;
                }
                else if (1 + x > dp[u][1]) {
                    dp[u][1] = 1 + x;
                    next[u][1] = i;
                }
            }
    };
    dfs1(0, -1, dfs1);

    auto dfs2 = [&](int u, int p, auto&& dfs) -> void {
        if (p != -1) {
            auto [x, y] = dp[p];
            if (next[p][0] == u)
                x = INT_MIN;
            if (next[p][1] == u)
                y = INT_MIN;
            if (y > x)
                swap(x, y);
            
            if (1 + x > dp[u][0]) {
                swap(dp[u][0], dp[u][1]);
                swap(next[u][0], next[u][1]);
                dp[u][0] = 1 + x;
                next[u][0] = p;
            }
            else if (1 + x > dp[u][1]) {
                dp[u][1] = 1 + x;
                next[u][1] = p;
            }

            if (1 + y > dp[u][1]) {
                dp[u][1] = 1 + y;
                next[u][1] = p;
            }
        }
        
        for (int& i : adj[u])
            if (i != p)
                dfs(i, u, dfs);
    };
    dfs2(0, -1, dfs2);

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
        ans = min(ans, max(dp[i][0], dp[i][1]));
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}