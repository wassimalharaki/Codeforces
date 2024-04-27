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
    
    v<char> color(n);
    auto dfs = [&](int u, auto&& dfs) -> bool {
        color[u] = 1;
        for (int& i : adj[u])
            if ((color[i] == 0 and dfs(i, dfs)) or color[i] == 1)
                return 1;
        color[u] = 2;
        return 0;
    };

    for (int i = 0; i < n; i++)
        if (color[i] == 0 and dfs(i, dfs))
            return 1;
    return 0;
}

void solve() {
    int n, k; cin >> n >> k;
 
    v<v<int>> adj(n);
    for (int j = 0; j < k; j++) {
        v<int> nums(n);
        for (int& a : nums) cin >> a;
        for (int i = 1; i < n - 1; i++) {
            int a = nums[i], b = nums[i + 1];
            a--, b--;
            adj[a].push_back(b);
        }
    }
    cout << (is_cyclic(adj) ? "NO" : "YES") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}