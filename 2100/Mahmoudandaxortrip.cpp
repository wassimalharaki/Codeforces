#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 20;

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int ans = 0;
    v<array<array<int, 2>, N>> dp(n);
    auto dfs = [&](int u, int p, auto&& self) -> void {
        for (int i = 0; i < N; i++)
            dp[u][i][((1 << i) & a[u]) > 0]++;
        ans += a[u];

        for (int& i : adj[u]) if (i != p) {
            self(i, u, self);
            for (int j = 0; j < N; j++) {
                ans += (dp[u][j][0] * dp[i][j][1] + dp[u][j][1] * dp[i][j][0]) << j;
                dp[u][j][((1 << j) & a[u]) > 0] += dp[i][j][0];
                dp[u][j][((1 << j) & a[u]) == 0] += dp[i][j][1];
            }
        }
    };
    dfs(0, -1, dfs);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}