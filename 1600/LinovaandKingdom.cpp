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
    int n, k; cin >> n >> k;

    v<v<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v<int> cnt(n + 1), use;
    auto dfs = [&](int u, int p, int d, auto&& dfs) -> void {
        cnt[u]++;
        for (int& i : adj[u])
            if (i != p) {
                dfs(i, u, d + 1, dfs);
                cnt[u] += cnt[i];
            }
        use.push_back(d - cnt[u] + 1);
    };
    dfs(1, -1, 0, dfs);
    sort(use.rbegin(), use.rend());
    cout << accumulate(use.begin(), use.begin() + k, 0ll) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}