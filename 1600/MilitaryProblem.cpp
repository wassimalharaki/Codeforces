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
    int n, q; cin >> n >> q;

    v<v<int>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
        int a; cin >> a;
        adj[a].push_back(i);
    }

    v<int> cnt(n + 1), pos(n + 1), order;
    auto dfs = [&](int u, auto&& dfs) -> void {
        order.push_back(u);
        pos[u] = order.size() - 1;
        cnt[u]++;
        for (int& i : adj[u]) {
            dfs(i, dfs);
            cnt[u] += cnt[i];
        }
    };
    dfs(1, dfs);

    while (q--) {
        int u, k; cin >> u >> k;
        if (k > cnt[u])
            cout << -1 << nl;
        else
            cout << order[pos[u] + k - 1] << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}