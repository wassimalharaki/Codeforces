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
    int n; cin >> n;

    v<v<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u; cin >> u; u--;
        adj[u].push_back(i);
    }

    v<array<int, 2>> a(n);
    for (auto& x : a)
        cin >> x[0] >> x[1];

    int ans = 0;
    auto dfs = [&](int u, auto&& dfs) -> int {
        int x = 0;

        for (int& i : adj[u])
            x += dfs(i, dfs);
        
        x = min(x, a[u][1]);
        if (x < a[u][0]) {
            ans++;
            x = a[u][1];
        }
        return x;
    };
    dfs(0, dfs);

    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}