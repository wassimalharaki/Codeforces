#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v<int> leaf(n), bud(n);
    int bcnt = 0, lcnt = 0;
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        for (int& i : adj[u]) if (i != p) {
            dfs(i, u, dfs);
            bud[u] += not bud[i];
        }
        leaf[u] = bud[u] == 0;
        bcnt += bud[u] > 0;
        lcnt += leaf[u];
    };
    dfs(0, -1, dfs);

    int ans = n + 1;
    auto dfs2 = [&](int u, int p, auto&& dfs2) -> void {
        bcnt -= bud[u] > 0;
        lcnt -= leaf[u];
        bool l = 1;
        for (int& i : adj[u]) if (i != p)
            l = 0, dfs2(i, u, dfs2);
        bcnt += bud[u] > 0;
        lcnt += leaf[u];
        if (not l) return;
        ans = min(ans, lcnt - bcnt);
    };
    dfs2(0, -1, dfs2);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}