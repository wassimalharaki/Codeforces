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

void solve() {
    int n; cin >> n;

    v<v<array<int, 2>>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; cin >> a >> b >> c;
        c--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    
    v<int> cnt(n + 1);
    auto dfs_cnt = [&](int u, int p, auto&& dfs_cnt) -> void {
        for (auto& [i, k] : adj[u])
            if (i != p) {
                if (k) cnt[i]++;
                dfs_cnt(i, u, dfs_cnt);
                cnt[u] += cnt[i];
            }
    };
    dfs_cnt(1, -1, dfs_cnt);

    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end(), [&](auto& l, auto& r) {
            return cnt[l[0]] > cnt[r[0]];
        });

    int bad = 0;
    v<int> ans;
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        if (adj[u].size() == 1 and p != -1) {
            if (bad) ans.push_back(u);
            bad = 0;
        }

        for (auto& [i, k] : adj[u])
            if (i != p) {
                if (k) bad++;
                dfs(i, u, dfs);
            }
    };
    dfs(1, -1, dfs);
    
    cout << ans.size() << nl;
    for (int& a : ans)
        cout << a << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}