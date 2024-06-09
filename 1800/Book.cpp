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

// O(V + E)
bool is_cyclic(v<v<int>>& adj) {
    int n = adj.size();
    
    v<char> c(n);
    auto dfs = [&](int u, auto&& dfs) -> bool {
        c[u] = 1;
        for (int& i : adj[u])
            if ((c[i] == 0 and dfs(i, dfs)) or c[i] == 1)
                return 1;
        c[u] = 2;
        return 0;
    };

    for (int i = 0; i < n; i++)
        if (c[i] == 0 and dfs(i, dfs))
            return 1;
    return 0;
}

void solve() {
    int n; cin >> n;

    v<v<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            adj[i].push_back(x - 1);
        }
    }

    if (is_cyclic(adj)) {
        cout << -1 << nl;
        return;
    }

    v<int> dp(n, -1);
    auto dfs = [&](int u, auto&& dfs) -> int {
        if (dp[u] != -1) return dp[u];

        for (int& i : adj[u])
            dp[u] = max(dp[u], dfs(i, dfs) + (i > u));
        dp[u] = max(dp[u], 1ll);
        return dp[u];
    };
    for (int i = 0; i < n; i++)
        dfs(i, dfs);
    cout << *max_element(dp.begin(), dp.end()) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}