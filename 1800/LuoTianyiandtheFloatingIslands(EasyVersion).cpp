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

const int mod = 1e9 + 7;

int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1;
    while (b) {
        int q = a / b;
        tie(x, x1) = make_pair(x1, x - q * x1);
        tie(y, y1) = make_pair(y1, y - q * y1);
        tie(a, b) = make_pair(b, a - q * b);
    }
    return a;
}

// O(log(min(a, b)))
int modinv(int a, const int m = mod) {
    int x, y;
    int g = gcd(a, m, x, y);
    return (g == 1 ? (x % m + m) % m : 0);
}

void solve() {
    int n, k; cin >> n >> k;

    if (k & 1) {
        cout << 1;
        return;
    }

    v adj(n, v<int>());
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v<int> dp(n), cnt(n);
    auto dfs1 = [&](int u, int p, auto&& dfs) -> void {
        for (int& i : adj[u])
            if (i != p) {
                dfs(i, u, dfs);
                cnt[u] += 1 + cnt[i];
                dp[u] += dp[i];
            }
        dp[u] += cnt[u];
    };
    dfs1(0, -1, dfs1);

    auto dfs2 = [&](int u, int p, int x, auto&& dfs) -> void {
        dp[u] += x;
        for (int& i : adj[u])
            if (i != p)
                dfs(i, u, dp[u] - dp[i] + n - 2 * (1 + cnt[i]), dfs);
    };
    dfs2(0, -1, 0, dfs2);

    int sum = 0;
    for (int& x : dp)
        sum += x + n - 1;
    cout << sum % mod * modinv(n * (n - 1)) % mod;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}