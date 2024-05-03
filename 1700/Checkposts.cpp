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

v<int> comp, comps;
void tarjan(v<v<int>>& adj) {
    int n = adj.size(), curr = 0;
    comp.resize(n, -1);
    v<int> disc(n), vis;

    auto dfs = [&](int u, auto&& dfs) -> int {
        int low = disc[u] = ++curr;
		vis.push_back(u);

		for (int& i : adj[u])
			if (comp[i] == -1)
                low = min(low, disc[i] ?: dfs(i, dfs));

		if (low == disc[u]) {
			comps.push_back(u);
			for (int i = -1; i != u;) {
                i = vis.back();
                comp[i] = u;
                vis.pop_back();
            }
		}
		return low;
    };

    for (int i = 0; i < n; i++)
        if (!disc[i]) dfs(i, dfs);
    reverse(comps.begin(), comps.end());
}

const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    int m; cin >> m;

    v<v<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
    }
    tarjan(adj);

    v<array<int, 2>> ans(n, {0, 1});
    for (int& u : comps)
        ans[u][0] = LLONG_MAX;
    
    for (int i = 0; i < n; i++)
        if (nums[i] < ans[comp[i]][0])
            ans[comp[i]] = {nums[i], 1};
        else if (nums[i] == ans[comp[i]][0])
            ans[comp[i]][1]++;

    int min_cost = 0, ways = 1;
    for (int& u : comps) {
        min_cost += ans[u][0];
        ways = (ways * ans[u][1]) % mod;
    }
    cout << min_cost << " " << ways << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}