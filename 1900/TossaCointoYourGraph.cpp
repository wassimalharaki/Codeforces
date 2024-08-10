#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

// O(V + E)
bool is_cyclic(vector<vector<int>>& adj, v<int>& alive) {
    int n = adj.size();

    vector<char> c(n);
    auto dfs = [&](int u, auto&& dfs) -> bool {
        c[u] = 1;
        for (int& i : adj[u])
            if (alive[i] and ((c[i] == 0 and dfs(i, dfs)) or c[i] == 1))
                return 1;
        c[u] = 2;
        return 0;
    };

    for (int i = 0; i < n; i++)
        if (alive[i] and c[i] == 0 and dfs(i, dfs))
            return 1;
    return 0;
}

void solve() {
    int n, m, k; cin >> n >> m >> k;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<v<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[--x].push_back(--y);
    }

    v<int> dp(n), alive(n);
    auto dfs = [&](int u, auto&& dfs) -> void {
        if (dp[u] != -1) return;
        dp[u] = 0;
        for (int& i : adj[u])
            if (alive[i]) {
                dfs(i, dfs);
                dp[u] = max(dp[u], 1 + dp[i]);
            }
    };

    auto check = [&](int x) -> bool {
        for (int i = 0; i < n; i++)
            alive[i] = a[i] <= x, dp[i] = -1;

        if (is_cyclic(adj, alive))
            return 1;

        for (int i = 0; i < n; i++)
            if (alive[i]) dfs(i, dfs);
        return *max_element(dp.begin(), dp.end()) >= k - 1;
    };

    int lo = 1, hi = 1e9, ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (check(mid))
            hi = mid - 1, ans = mid;
        else
            lo = mid + 1;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}