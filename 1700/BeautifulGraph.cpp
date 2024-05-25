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

const int mod = 998244353;

// O(log(b))
int binpow(int a, int b, const int m = mod) {
    a %= m;
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, m; cin >> n >> m;

    bool ok = 1;
    v<v<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 1, cnt, sz;
    v<int> vis(n);
    auto dfs = [&](int u, int x, auto&& dfs) -> void {
        cnt += x, sz++, vis[u] = x + 1;
        for (int& i : adj[u])
            if (not vis[i])
                dfs(i, !x, dfs);
            else if (vis[u] == vis[i])
                ans = 0;
    };

    for (int i = 0; i < n; i++)
        if (not vis[i]) {
            if (adj[i].empty())
                ans = ans * 3 % mod;
            else {
                cnt = 0, sz = 0;
                dfs(i, 0, dfs);
                ans = ans * (binpow(2, cnt) + binpow(2, sz - cnt)) % mod;
            }
        }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}