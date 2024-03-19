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

    int ans = 0;
    v<int> size(n + 1);
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        size[u]++;
        for (int& i : adj[u])
            if (i != p) {
                dfs(i, u, dfs);
                size[u] += size[i];
                if (!(size[i] & 1)) {
                    ans++;
                    size[u] -= size[i];
                }
            }
    };
    dfs(1, -1, dfs);
    cout << (size[1] & 1 ? -1 : ans);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}