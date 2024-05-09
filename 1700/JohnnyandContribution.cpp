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

// O(V + E)
v<int> topsort(v<v<int>>& adj) {
    int n = adj.size();
    v<char> vis(n);
    v<int> order;

    auto dfs = [&](int u, auto&& dfs) -> void {
        vis[u] = 1;
        for (int& i : adj[u])
            if (not vis[i])
                dfs(i, dfs);
        order.push_back(u);
    };

    for (int i = 0; i < n; i++)
        if (not vis[i]) dfs(i, dfs);
    reverse(order.begin(), order.end());

    return order;
}

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    v<v<int>> new_adj(n);
    for (int i = 0; i < n; i++) {
        v<array<int, 2>> mex;
        for (int& u : adj[i])
            mex.push_back({nums[u], u});
        sort(mex.begin(), mex.end());

        int x = 1;
        for (int j = 0; j < mex.size(); j++) {
            if (mex[j][0] == x) {
                new_adj[mex[j][1]].push_back(i);
                x++;
            }
        }
        if (x != nums[i]) {
            cout << -1 << nl;
            return;
        }
    }

    if (is_cyclic(new_adj)) {
        cout << -1 << nl;
        return;
    }

    auto ans = topsort(new_adj);
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