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

const int mod = 1e9 + 7;

// O(log(b))
int binpow(int a, int b, const int m = mod) {
    a %= m;
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n; cin >> n;

    v<v<array<int, 2>>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }

    int m; cin >> m;

    v<int> pf(m);
    for (int& x : pf) cin >> x;
    sort(pf.begin(), pf.end());

    v<array<int, 2>> a(n - 1);
    v<int> cnt(n);
    auto dfs1 = [&](int u, int p, auto&& dfs) -> void {
        cnt[u]++;

        for (auto& [i, j] : adj[u])
            if (i != p) {
                dfs(i, u, dfs);
                cnt[u] += cnt[i];
                a[j] = {(n - cnt[i]) * cnt[i], j};
            }
    };
    dfs1(0, -1, dfs1);
    sort(a.begin(), a.end());

    v<int> b(n - 1, 1);
    for (int i = n - 2, j = min(m - 1, n - 2); i >= 0 and j >= 0; i--, j--)
        b[a[i][1]] = pf[j];
    
    for (int i = min(m, n - 1); i < m; i++)
        b[a.back()[1]] = b[a.back()[1]] * pf[i] % mod;
    
    v<int> dp(n);
    auto dfs2 = [&](int u, int p, auto&& dfs) -> void {
        for (auto& [i, j] : adj[u])
            if (i != p) {
                dfs(i, u, dfs);
                dp[u] = (dp[u] + dp[i] + cnt[i] * b[j]) % mod;
            }
    };
    dfs2(0, -1, dfs2);

    int ans = 0;
    auto dfs3 = [&](int u, int p, int k, auto&& dfs) -> void {
        if (p != -1) {
            int x = dp[p] - dp[u] - cnt[u] * b[k];
            x = (x % mod + mod) % mod;
            dp[u] = (dp[u] + x + (n - cnt[u]) * b[k]) % mod;
        }
        ans = (ans + dp[u]) % mod;

        for (auto& [i, j] : adj[u])
            if (i != p)
                dfs(i, u, j, dfs);
    };
    dfs3(0, -1, -1, dfs3);

    cout << ans * binpow(2, mod - 2) % mod << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}