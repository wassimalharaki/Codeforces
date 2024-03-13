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

int binpow(int a, int b, const int m = 1e9 + 7) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

const int mod = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;
    
    v<v<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int ans = binpow(n, k), x = 0;
    v<int> vis(n + 1);
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        x++;
        vis[u] = 1;
        for (auto& [i, c]: adj[u])
            if (i != p and c != 1)
                dfs(i, u, dfs);
    };

    for (int i = 1; i <= n; i++)
        if (not vis[i]) {
            x = 0;
            dfs(i, -1, dfs);
            ans = (ans - binpow(x, k)) % mod;
        }
    cout << (ans + mod) % mod << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}