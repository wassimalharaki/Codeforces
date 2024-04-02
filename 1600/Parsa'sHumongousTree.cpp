#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;

    v<array<int, 2>> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i][0] >> nums[i][1];

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v<array<int, 2>> dp(n, {0, 0});
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        for (int& i : adj[u]) {
            if (i == p) continue;
            dfs(i, u, dfs);
            int a = abs(nums[u][0] - nums[i][0]) + dp[i][0];
            int b = abs(nums[u][0] - nums[i][1]) + dp[i][1];
            int c = abs(nums[u][1] - nums[i][0]) + dp[i][0];
            int d = abs(nums[u][1] - nums[i][1]) + dp[i][1];
            dp[u][0] += max(a, b);
            dp[u][1] += max(c, d);
        }
    };
    dfs(0, -1, dfs);
    cout << max(dp[0][1], dp[0][0]) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}