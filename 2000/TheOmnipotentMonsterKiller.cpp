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
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v dp(N + 1, v<int>(n));
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        for (int i = 1; i < N; i++)
            dp[i][u] = i * a[u];

        for (int& i : adj[u])
            if (i != p)
                dfs(i, u, dfs);
        
        for (int i = 1; i < N; i++)
            for (int& k : adj[u]) if (k != p) {
                int x = LLONG_MAX;
                for (int j = 1; j < N; j++)
                    if (i != j)
                        x = min(x, dp[j][k]);
                dp[i][u] += x;
            }
    };
    dfs(0, -1, dfs);
    
    int ans = LLONG_MAX;
    for (int i = 1; i < N; i++)
        ans = min(ans, dp[i][0]);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}