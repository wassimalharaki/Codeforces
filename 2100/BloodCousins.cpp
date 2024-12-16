#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

const int N = 20;

void solve() {
    int n; cin >> n;

    v<v<int>> adj(n), go(N, v<int>(n));
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        go[0][i] = p ? p - 1 : i;
        if (p) adj[p - 1].push_back(i);
    }

    for (int i = 1; i < N; i++)
        for (int j = 0; j < n; j++)
            go[i][j] = go[i - 1][go[i - 1][j]];

    int t = 0;
    v<int> d(n), in(n), out(n);
    v<v<int>> at(n);
    auto dfs = [&](int u, int p, auto&& self) -> void {
        in[u] = t++;
        d[u] = p == -1 ? 0 : 1 + d[p];
        at[d[u]].push_back(in[u]);

        for (int& i : adj[u])
            if (i != p) self(i, u, self);
        out[u] = t;
    };
    for (int i = 0; i < n; i++)
        if (go[0][i] == i)
            dfs(i, -1, dfs);
    
    auto jump = [&](int a, int k) -> int {
        while (k > 0) {
            a = go[__builtin_ctz(k)][a];
            k -= k & - k;
        }
        return a;
    };

    auto count = [&](int x, int l, int r) -> int {
        return lower_bound(at[x].begin(), at[x].end(), r)
             - lower_bound(at[x].begin(), at[x].end(), l);
    };

    int m; cin >> m;
    while (m--) {
        int u, p; cin >> u >> p;
        int i = jump(--u, p);
        if (p > d[u])
            cout << 0 << " ";
        else
            cout << count(d[u], in[i], out[i]) - 1 << " ";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}