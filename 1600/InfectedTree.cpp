#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

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

    v<int> cnt(n + 1);
    auto dfs1 = [&](int u, int p, auto&& dfs1) -> void {
        cnt[u]++;
        for (int& i : adj[u])
            if (i != p) {
                dfs1(i, u, dfs1);
                cnt[u] += cnt[i];
            }
    };
    dfs1(1, -1, dfs1);

    auto dfs2 = [&](int u, int p, auto&& dfs2) -> int {
        if (adj[u].size() == 1)
            return 0;
        else if (adj[u].size() == 2)
            return cnt[u] - 2;
        else {
            v<int> nums;
            for (int& i : adj[u])
                if (i != p)
                    nums.push_back(i);
            int x = cnt[nums[0]] - 1 + dfs2(nums[1], u, dfs2);
            int y = cnt[nums[1]] - 1 + dfs2(nums[0], u, dfs2);
            return max(x, y);
        }
    };

    if (adj[1].size() == 1)
        cout << cnt[1] - 2 << nl;
    else {
        auto& nums = adj[1];
        int x = cnt[nums[0]] - 1 + dfs2(nums[1], 1, dfs2);
        int y = cnt[nums[1]] - 1 + dfs2(nums[0], 1, dfs2);
        cout << max(x, y) << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}