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
    int n, m; cin >> n >> m;

    v<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool ok = 1;
    v<int> cnt(n);
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        cnt[u] += a[u];
        
        int h = 0;
        for (int& i : adj[u])
            if (i != p) {
                dfs(i, u, dfs);
                cnt[u] += cnt[i];
                h -= (b[i] + cnt[i]) / 2;
            }
        
        ok &= b[u] >= -cnt[u] and b[u] <= cnt[u];
        ok &= (b[u] + cnt[u]) & 1 ^ 1;
        ok &= h + (b[u] + cnt[u]) / 2 >= 0;
    };
    dfs(0, -1, dfs);

    cout << (ok ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}