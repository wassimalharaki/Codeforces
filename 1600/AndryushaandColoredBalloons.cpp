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

    v<v<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    v<int> ans(n + 1); ans[1] = 1;

    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        int x = 1;
        while (x == ans[u] or x == ans[p])
            x++;
        for (int& i : adj[u]) {
            if (i == p) continue;
            ans[i] = x++;
            while (x == ans[u] or x == ans[p])
                x++;
        }

        for (int& i : adj[u])
            if (i != p)
                dfs(i, u, dfs);
    };
    dfs(1, 0, dfs);

    cout << *max_element(ans.begin(), ans.end()) << nl;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}