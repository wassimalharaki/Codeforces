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
    int n, k; cin >> n >> k;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 0;
    v<v<int>> cnt(n, v<int>(k + 1));
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        cnt[u][0]++;
        for (int& i : adj[u])
            if (i != p) {
                dfs(i, u, dfs);
                for (int d = 0; d < k; d++)
                    cnt[u][d + 1] += cnt[i][d];
            }
        ans += cnt[u][k];
    };
    dfs(0, -1, dfs);

    v<int> prev(k + 1);
    auto dfs2 = [&](int u, int p, auto&& dfs) -> void {
        if (p != -1) {
            copy(cnt[u].begin(), cnt[u].end(), prev.begin());
            for (int d = 0; d < k; d++)
                cnt[p][d + 1] -= prev[d];

            for (int d = 0; d < k; d++)
                cnt[u][d + 1] += cnt[p][d];

            for (int d = 0; d < k; d++)
                cnt[p][d + 1] += prev[d];
            ans += cnt[u][k] - prev[k];
        }

        for (int& i : adj[u])
            if (i != p)
                dfs(i, u, dfs);
    };
    dfs2(0, -1, dfs2);

    cout << (ans >> 1);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}