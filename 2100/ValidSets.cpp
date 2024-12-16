#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 2e3 + 1;
const int mod = 1e9 + 7;

void add(int& a, int b) {
    a = (a + (b % mod + mod) % mod) % mod;
}

void solve() {
    int n, d; cin >> d >> n;

    v<v<int>> a(N);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x].push_back(i);
    }

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    v<int> alive(n), vis(n);
    for (int i = 0; i <= d; i++)
        for (int& u : a[i])
            alive[u] = 1;
    
    auto dfs = [&](int u, auto&& self) -> array<int, 2> {
        if (vis[u]) return {0, 0};
        if (not alive[u]) return {0, 0};
        vis[u] = 1;

        array<int, 2> x{1, 1};
        for (int& i : adj[u]) {
            array<int, 2> y = self(i, self);
            add(x[1], y[1]);
            add(x[1], x[0] * y[0]);
            x[0] = x[0] * (y[0] + 1) % mod;
        }
        return x;
    };

    auto get = [&]() -> int {
        fill(vis.begin(), vis.end(), 0);
        int x = 0;
        for (int i = 0; i < n; i++)
            add(x, dfs(i, dfs)[1]);
        return x;
    };

    int ans = get();
    for (int i = d + 1; i < N; i++) {
        for (int& u : a[i - d - 1])
            alive[u] = 0;
        int prev = get();
        for (int& u : a[i])
            alive[u] = 1;
        add(ans, get() - prev);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}