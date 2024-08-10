#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    v<v<int>> adj(n);
    for (int& x : a) cin >> x;
    for (int i = 1; i < n; i++) {
        int p; cin >> p;
        adj[--p].push_back(i);
    }

    int m = 0;
    v<int> dp(n);
    auto dfs = [&](int u, auto&& dfs) -> void {
        if (adj[u].empty()) {
            m++, dp[u]++;
            return;
        }
        if (a[u]) dp[u] = 1e9;
        for (int& i : adj[u]) {
            dfs(i, dfs);
            dp[u] = a[u] ? min(dp[u], dp[i]) : dp[u] + dp[i];
        }
    };
    dfs(0, dfs);
    cout << m - dp[0] + 1 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}