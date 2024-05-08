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

// O(V + E)
v<int> get_cycle(v<v<int>>& adj) {
    int n = adj.size(), l = -1, r = -1;
    v<int> p(n, -1);
    v<char> c(n);
    
    auto dfs = [&](int u, int par, auto&& dfs) -> bool {
        c[u] = 1;
        for (int& i : adj[u]) if (i != par) {
            if (c[i] == 0) {
                p[i] = u;
                if (dfs(i, u, dfs))
                    return 1;
            }
            else if (c[i] == 1) {
                l = i;
                r = u;
                return 1;
            }
        }
        c[u] = 2;
        return 0;
    };

    for (int i = 0; i < n; i++)
        if (c[i] == 0 and dfs(i, -1, dfs))
            break;
    if (r == -1) return {};

    v<int> cycle{l};
    for (int u = r; u != l; u = p[u])
        cycle.push_back(u);
    cycle.push_back(l);
    reverse(cycle.begin(), cycle.end());

    return cycle;
}

void solve() {
    int n, a, b; cin >> n >> a >> b;
    a--, b--;

    v<v<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    v<int> cyc = get_cycle(adj);
    v<char> flag(n);
    for (int& i : cyc)
        flag[i] = 1;

    queue<array<int, 2>> q;
    v<char> vis(n);
    vis[b] = 1;
    q.push({b, 0});

    int pnt, me;
    while (q.size()) {
        auto [u, d] = q.front();
        q.pop();

        if (flag[u]) {
            pnt = u, me = d;
            while (q.size()) q.pop();
            break;
        }

        for (int& i : adj[u])
            if (not vis[i]) {
                vis[i] = 1;
                q.push({i, d + 1});
            }
    }

    fill(vis.begin(), vis.end(), 0ll);
    q.push({a, 0});
    vis[a] = 1;

    int you;
    while (q.size()) {
        auto [u, d] = q.front();
        q.pop();

        if (u == pnt) {
            you = d;
            break;
        }

        for (int& i : adj[u])
            if (not vis[i]) {
                vis[i] = 1;
                q.push({i, d + 1});
            }
    }

    cout << (me < you ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}