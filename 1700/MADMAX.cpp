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

    v<v<array<int, 2>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        char c; cin >> c;
        a--, b--;
        adj[a].push_back({b, c - 'a'});
    }

    v<v<v<v<int>>>> ans(n, v<v<v<int>>>(n, v<v<int>>(26, v<int>(2, -1))));
    auto go = [&](int i, int j, int prev, bool alt, auto&& go) -> bool {
        if (ans[i][j][prev][alt] != -1)
            return ans[i][j][prev][alt];

        if (alt) {
            for (auto& [u, c] : adj[i])
                if (c >= prev)
                    if (!go(u, j, c, 0, go))
                        return ans[i][j][prev][alt] = 1;
            return ans[i][j][prev][alt] = 0;
        }
        else {
            for (auto& [u, c] : adj[j])
                if (c >= prev)
                    if (!go(i, u, c, 1, go))
                        return ans[i][j][prev][alt] = 1;
            return ans[i][j][prev][alt] = 0;
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            go(i, j, 0, 1, go);
            cout << (ans[i][j][0][1] ? 'A' : 'B');
        }
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}