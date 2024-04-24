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
    int n, m; cin >> n >> m;

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    v<v<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v<set<int>> colors(*max_element(nums.begin(), nums.end()) + 1);
    v<bool> vis(n + 1);
    auto dfs = [&](int u, auto&& dfs) -> void {
        for (int& i : adj[u])
            colors[nums[u - 1]].insert(nums[i - 1]);

        for (int& i : adj[u])
            if (not vis[i]) {
                vis[i] = 1;
                dfs(i, dfs);
            }
    };

    for (int i = 1; i <= n; i++)
        if (not vis[i]) {
            vis[i] = 1;
            dfs(i, dfs);
        }

    sort(nums.begin(), nums.end());
    int max = -1, ans;
    for (int i = 1; i < colors.size(); i++) {
        if (not binary_search(nums.begin(), nums.end(), i))
            continue;
        colors[i].erase(i);
        if ((int) colors[i].size() > max) {
            max = colors[i].size();
            ans = i;
        }
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}