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

void solve() {
    int n, m; cin >> n >> m;

    v<int> imp(n);
    for (int& x : imp) cin >> x;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v<int> par(n), cnt(n);
    // {-size, i}
    v<set<array<int, 2>>> child(n);
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        par[u] = p;
        cnt[u]++;
        for (int& i : adj[u])
            if (i != p) {
                dfs(i, u, dfs);
                cnt[u] += cnt[i];
                imp[u] += imp[i];
                child[u].insert({-cnt[i], i});
            }
    };
    dfs(0, -1, dfs);

    while (m--) {
        int t, x; cin >> t >> x; x--;
        if (t == 1) {
            cout << imp[x] << nl;
            continue;
        }
        if (child[x].empty())
            continue;
        
        int to_rotate = (*child[x].begin())[1];
        int p = par[x];
        par[to_rotate] = p;

        int prev_size = cnt[to_rotate];
        int prev_imp = imp[to_rotate];
        cnt[to_rotate] += cnt[x] - prev_size;
        imp[to_rotate] += imp[x] - prev_imp;

        child[p].erase({-cnt[x], x});
        par[x] = to_rotate;
        imp[x] -= prev_imp;
        cnt[x] -= prev_size;
        child[to_rotate].insert({-cnt[x], x});
        child[x].erase(child[x].begin());

        child[p].insert({-cnt[to_rotate], to_rotate});
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}