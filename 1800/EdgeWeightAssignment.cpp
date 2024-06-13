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
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int rt = -1;
    for (int i = 0; i < n; i++)
        if (adj[i].size() > 1) {
            rt = i;
            break;
        }

    int o = 0, e = 0, ans = n - 1;
    auto dfs = [&](int u, int p, int d, auto&& dfs) -> int {
        if (adj[u].size() == 1)
            d & 1 ? o++ : e++;
        
        int x = 0;
        for (int& i : adj[u])
            if (i != p)
                x += dfs(i, u, d + 1, dfs);
        ans -= max(0ll, x - 1);
        return adj[u].size() == 1;
    };
    dfs(rt, -1, 0, dfs);

    cout << (o and e ? 3 : 1) << " " << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}