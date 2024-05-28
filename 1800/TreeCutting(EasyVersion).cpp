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
 
    v<int> nums(n);
    int total_red = 0, total_blue = 0;
    for (int& a : nums) {
        cin >> a;
        if (a == 1) total_red++;
        if (a == 2) total_blue++;
    }
 
    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    v<array<int, 2>> cnts(n);
    int ans = 0;
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        cnts[u][0] += (nums[u] == 1);
        cnts[u][1] += (nums[u] == 2);
        for (int& i : adj[u]) {
            if (i == p) continue;
            dfs(i, u, dfs);
            cnts[u][0] += cnts[i][0];
            cnts[u][1] += cnts[i][1];

            array<int, 2> above{total_red - cnts[i][0], total_blue - cnts[i][1]};
            array<int, 2> below{cnts[i][0], cnts[i][1]};
            if (above[0] == 0 and below[1] == 0)
                ans++;
            else if (above[1] == 0 and below[0] == 0)
                ans++;
        }
    };
    dfs(0, -1, dfs);
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}