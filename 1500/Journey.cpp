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

    v<v<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    double ans = 0;
    auto dfs = [&](int u, int p, int d, double val, auto&& dfs) -> void {
        if (adj[u].size() == 1 and adj[u][0] == p)
            ans += val * d;
        
        int sz = adj[u].size() - (p != -1);
        for (int& i : adj[u])
            if (i != p)
                dfs(i, u, d + 1, val * 1.0 / sz, dfs);
    };
    dfs(1, -1, 0, 1, dfs);
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}