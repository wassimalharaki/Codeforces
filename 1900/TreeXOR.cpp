#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

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

    v<int> dp(n), cnt(n);
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        cnt[u]++;
        for (int& i : adj[u])
            if (i != p) {
                dfs(i, u, dfs);
                dp[u] += dp[i] + (a[i] ^ a[u]) * cnt[i];
                cnt[u] += cnt[i];
            }
    };
    dfs(0, -1, dfs);

    auto reroot = [&](int u, int p, auto&& reroot) -> void {
        if (p != -1) {
            int x = dp[p];
            x -= dp[u] + (a[u] ^ a[p]) * cnt[u];
            dp[u] += (a[u] ^ a[p]) * (cnt[p] - cnt[u]) + x;
            cnt[u] = cnt[p];
        }

        for (int& i : adj[u])
            if (i != p)
                reroot(i, u, reroot);
    };
    reroot(0, -1, reroot);

    for (int& x : dp)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}