#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

struct state {
    int i = -1;
    bool k = 0;

    state() {}
    state(int _i, bool _k) {
        tie(i, k) = make_tuple(_i, _k);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    array<int, 3> cnt;
    cin >> cnt[0] >> cnt[1] >> cnt[2];

    v<v<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int rt = -1;
    bool ok = 1;
    v<int> vis(n), c(n), root;
    v<array<v<int>, 2>> sets(n);
    auto dfs = [&](int u, bool b, auto&& self) -> void {
        if (vis[u]) return;
        vis[u] = 1;
        c[u] = b;
        sets[rt][b].push_back(u);

        for (int& i : adj[u])
            if (vis[i] and c[u] == c[i])
                ok = 0;

        for (int& i : adj[u])
            self(i, !b, self);
    };

    for (int i = 0; i < n; i++)
        if (not vis[i]) {
            rt = i;
            root.push_back(i);
            dfs(i, 0, dfs);
        }

    if (not ok)
        return void(cout << "NO" << nl);

    v dp(n + 1, v<state>(n + 1, state(-1, 0)));
    dp[0][0] = state(INT_MAX, 0);
    for (int i = 0; i < (int) root.size(); i++)
        for (int j = 0; j <= n; j++)
            if (dp[i][j].i != -1)
                for (int k = 0; k < 2; k++)
                    if (j + (int) sets[root[i]][k].size() <= n)
                        dp[i + 1][j + sets[root[i]][k].size()] = state(root[i], k);

    if (dp[root.size()][cnt[1]].i == -1)
        return void(cout << "NO" << nl);

    v<int> ans(n);
    int j = cnt[1];
    for (int i = root.size(); i; i--) {
        for (int& u : sets[dp[i][j].i][dp[i][j].k])
            ans[u] = 2;
        j -= sets[dp[i][j].i][dp[i][j].k].size();
    }

    for (int i = 0; i < n and cnt[0]; i++)
        if (not ans[i]) ans[i] = 1, cnt[0]--;
    for (int i = 0; i < n and cnt[2]; i++)
        if (not ans[i]) ans[i] = 3, cnt[2]--;

    cout << "YES" << nl;
    for (int& x : ans)
        cout << x;
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}