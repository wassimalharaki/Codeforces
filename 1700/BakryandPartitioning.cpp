#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, k; cin >> n >> k;

    v<int> a(n);
    int all = 0;
    for (int& x : a)
        cin >> x, all ^= x;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    if (all == 0) {
        cout << "YES" << nl;
        return;
    }

    if (k == 2) {
        cout << "NO" << nl;
        return;
    }

    v<int> me(n), cnt(n);
    bool ok = 0;
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        me[u] = a[u];

        int x = 0;
        for (int& i : adj[u])
            if (i != p) {
                dfs(i, u, dfs);
                me[u] ^= me[i];
                cnt[u] |= cnt[i];
                x += cnt[i];
            }

        cnt[u] |= me[u] == all;
        if (x >= 2 or (x == 1 and me[u] == 0)) ok = 1;
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