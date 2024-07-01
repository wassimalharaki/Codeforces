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
    int n, m, T; cin >> n >> m >> T;

    v<v<array<int, 2>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c});
    }

    v dp(n, v<array<int, 2>>(n + 1, {INT_MAX, -1}));
    dp[0][1][0] = 0;
    queue<array<int, 3>> q;
    q.push({0, 1, 0});

    while (q.size()) {
        auto [u, d, t] = q.front();
        q.pop();
        if (t > T) continue;
        if (u == n - 1) continue;
        if (t > dp[u][d][0]) continue;

        for (auto& [i, c] : adj[u])
            if (t + c < dp[i][d + 1][0]) {
                q.push({i, d + 1, t + c});
                dp[i][d + 1][0] = t + c;
                dp[i][d + 1][1] = u;
            }
    }

    int i = n;
    for (; i >= 0; i--)
        if (dp[n - 1][i][0] <= T)
            break;

    v<int> ans;
    int u = n - 1;
    for (; u != -1; u = dp[u][i--][1])
        ans.push_back(u);
    reverse(ans.begin(), ans.end());

    cout << ans.size() << nl;
    for (int& x : ans)
        cout << x + 1 << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}