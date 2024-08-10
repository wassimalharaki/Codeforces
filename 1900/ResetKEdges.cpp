#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, k; cin >> n >> k;

    v<v<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int p; cin >> p;
        adj[--p].push_back(i);
    }

    int x = 0, y = 0;
    auto dfs = [&](int u, auto&& dfs) -> int {
        int me = 0;
        for (int& i : adj[u]) {
            int z = 1 + dfs(i, dfs);
            if (u and z == x)
                y++, z = 0;
            me = max(me, z);
        }
        return me;
    };

    int lo = 1, hi = n, ans = n;
    while (lo <= hi) {
        x = (lo + hi) / 2, y = 0;
        dfs(0, dfs);

        if (y <= k)
            hi = x - 1, ans = x;
        else
            lo = x + 1;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}