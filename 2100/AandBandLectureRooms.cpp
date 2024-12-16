#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

const int N = 20;

void solve() {
    int n; cin >> n;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int t = 0;
    v<int> d(n), in(n), out(n), sz(n);
    v<v<int>> go(N, v<int>(n));
    auto dfs = [&](int u, int p, auto&& self) -> int {
        in[u] = t++, sz[u] = 1;
        d[u] = p == -1 ? 0 : 1 + d[p];
        go[0][u] = p == -1 ? u : p;

        for (int& i : adj[u]) if (i != p)
            sz[u] += self(i, u, self);

        out[u] = t;
        return sz[u];
    };
    dfs(0, -1, dfs);

    for (int i = 1; i < N; i++)
        for (int j = 0; j < n; j++)
            go[i][j] = go[i - 1][go[i - 1][j]];
    
    auto jump = [&](int a, int k) -> int {
        while (k > 0) {
            a = go[__builtin_ctz(k)][a];
            k -= k & - k;
        }
        return a;
    };
    
    auto lca = [&](int a, int b) -> int {
        a = jump(a, d[a] - d[b]);
        b = jump(b, d[b] - d[a]);
        if (a == b) return a;
        
        int c = a;
        for (int i = N - 1; i >= 0; i--)
            if (go[i][a] == go[i][b])
                c = go[i][a];
            else
                a = go[i][a], b = go[i][b];
        return c;
    };

    auto dist = [&](int a, int b) -> int {
        return d[a] + d[b] - 2 * d[lca(a, b)];
    };

    int m; cin >> m;
    
    v<int> ans(m);
    v<v<array<int, 3>>> q(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        int x = dist(--a, --b);
        if (a == b)
            ans[i] = n;
        else if ((x & 1) ^ 1)
            q[jump(d[b] > d[a] ? b : a, x / 2)].push_back({a, b, i});
    }

    auto reroot = [&](int u, int p, auto&& self) -> void {
        if (p != -1) {
            sz[p] -= sz[u];
            sz[u] += sz[p];
        }

        int k = adj[u].size();
        for (auto& [a, b, i] : q[u]) {
            ans[i] = n;
            if (in[a] < in[u] or out[u] <= in[a])
                ans[i] -= sz[p];
            else {
                int lo = 0, hi = k - 1, j = k - 1;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;

                    if (in[adj[u][mid]] <= in[a])
                        lo = mid + 1, j = mid;
                    else
                        hi = mid - 1;
                }
                ans[i] -= sz[adj[u][j]];
            }

            if (in[b] < in[u] or out[u] <= in[b])
                ans[i] -= sz[p];
            else {
                int lo = 0, hi = k - 1, j = k - 1;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;

                    if (in[adj[u][mid]] <= in[b])
                        lo = mid + 1, j = mid;
                    else
                        hi = mid - 1;
                }
                ans[i] -= sz[adj[u][j]];
            }
        }

        for (int& i : adj[u])
            if (i != p) self(i, u, self);

        if (p != -1) {
            sz[u] -= sz[p];
            sz[p] += sz[u];
        }
    };
    reroot(0, -1, reroot);

    for (int& x : ans)
        cout << x << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}