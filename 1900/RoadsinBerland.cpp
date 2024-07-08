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

    int ans = 0;
    v adj(n, v<int>(n));
    for (auto& x : adj)
        for (auto& y : x) {
            cin >> y;
            ans += y;
        }

    int q; cin >> q;
    while (q--) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        if (adj[a][b] <= c) {
            cout << ans / 2 << " ";
            continue;
        }

        ans += 2 * (c - adj[a][b]);
        adj[a][b] = adj[b][a] = c;

        for (int k : {a, b})
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (adj[i][j] > adj[i][k] + adj[k][j]) {
                        ans += adj[i][k] + adj[k][j] - adj[i][j];
                        adj[i][j] = adj[i][k] + adj[k][j];
                    }
        cout << ans / 2 << " ";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}