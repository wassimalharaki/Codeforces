#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

const int N = 301;

void solve() {
    int n; cin >> n;

    v<v<int>> adj(n, v<int>(n));
    v<bitset<N>> reach(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a][b] = adj[b][a] = 1;
    }

    int k = 0;
    {
        auto dfs = [&](int u, int p, auto&& dfs) -> void {
            reach[u][u] = 1;
            for (int i = 0; i < n; i++)
                if (i != p and adj[u][i]) {
                    dfs(i, u, dfs);
                    reach[u] |= reach[i];
                }
            k += reach[u].count() == 1;
        };
        dfs(0, -1, dfs);
    }

    v<int> a(k), path;
    for (int& x : a)
        cin >> x, x--;

    int j = 0;
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        path.push_back(u);
        if (u == a[j]) j++;

        v<int> dead(n);
        for (int i = 0; i < n and j < k; i++) {
            if (i == p) continue;
            if (not adj[u][i]) continue;
            if (dead[i]) continue;
            if (not reach[i][a[j]]) continue;
            dfs(i, u, dfs);
            dead[i] = 1, i = -1;
            path.push_back(u);
        }
    };
    dfs(0, -1, dfs);

    if ((int) path.size() != 2 * n - 1)
        cout << -1 << nl;
    else {
        for (int& x : path)
            cout << x + 1 << " ";
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}