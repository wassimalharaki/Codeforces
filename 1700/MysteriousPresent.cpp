#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, w, h; cin >> n >> w >> h;

    v<array<int, 2>> a(n + 1);
    a[0] = {w, h};
    for (int i = 1; i <= n; i++)
        cin >> a[i][0] >> a[i][1];
    
    v<v<char>> adj(n + 1, v<char>(n + 1));
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            if (a[i][0] < a[j][0] and a[i][1] < a[j][1])
                adj[i][j] = 1;
    
    v<int> dp(n + 1), next(n + 1, -1);
    auto dfs = [&](int u, auto&& dfs) -> void {
        if (dp[u]) return;

        for (int i = 0; i <= n; i++)
            if (adj[u][i]) {
                dfs(i, dfs);
                if (dp[i] + 1 > dp[u]) {
                    dp[u] = dp[i] + 1;
                    next[u] = i;
                }
            }
    };
    dfs(0, dfs);

    int u = next[0];
    v<int> ans;
    while (u != -1) {
        ans.push_back(u);
        u = next[u];
    }
    cout << ans.size() << nl;
    for (int& a : ans)
        cout << a << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}