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

// O(V + E)
bool is_cyclic(v<v<int>>& adj) {
    int n = adj.size();
    
    v<char> c(n);
    auto dfs = [&](int u, auto&& dfs) -> bool {
        c[u] = 1;
        for (int& i : adj[u])
            if ((c[i] == 0 and dfs(i, dfs)) or c[i] == 1)
                return 1;
        c[u] = 2;
        return 0;
    };

    for (int i = 0; i < n; i++)
        if (c[i] == 0 and dfs(i, dfs))
            return 1;
    return 0;
}

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;

    v<v<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a - 1].push_back(b - 1);
    }

    if (is_cyclic(adj)) {
        cout << -1 << nl;
        return;
    }

    v<int> vis(n), cnt(n);
    auto dfs = [&](int u, char c, auto&& dfs) -> void {
        cnt[u] += s[u] == c;
        vis[u] = 1;

        for (int& i : adj[u]) {
            if (not vis[i]) dfs(i, c, dfs);
            cnt[u] = max(cnt[u], (s[u] == c) + cnt[i]);
        }
    };

    auto get = [&](char c) -> int {
        fill(vis.begin(), vis.end(), 0ll);
        fill(cnt.begin(), cnt.end(), 0ll);
        for (int i = 0; i < n; i++)
            if (not vis[i])
                dfs(i, c, dfs);
        return *max_element(cnt.begin(), cnt.end());
    };

    int ans = 0;
    for (int i = 'a'; i <= 'z'; i++)
        ans = max(ans, get(i));
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}