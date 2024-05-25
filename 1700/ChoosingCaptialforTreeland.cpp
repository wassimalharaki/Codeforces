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

    v<v<array<int, 2>>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back({b, 0});
        adj[b].push_back({a, 1});
    }

    int min = 0;
    auto dfs1 = [&](int u, int p, auto&& dfs) -> void {
        for (auto& [i, c] : adj[u])
            if (i != p) {
                min += c;
                dfs(i, u, dfs);
            }
    };
    dfs1(0, -1, dfs1);

    v<int> ans;
    auto dfs2 = [&](int u, int p, int curr, auto&& dfs) -> void {
        if (curr < min)
            ans = {u}, min = curr;
        else if (curr == min)
            ans.push_back(u);

        for (auto& [i, c] : adj[u])
            if (i != p)
                dfs(i, u, curr + (c ? -1 : 1), dfs);
    };
    dfs2(0, -1, min, dfs2);

    sort(ans.begin(), ans.end());
    cout << min << nl;
    for (int& a : ans)
        cout << a + 1 << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}