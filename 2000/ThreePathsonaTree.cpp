#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v<int> dis(n);
    auto dfs = [&](int u, int p, int d, auto&& dfs) -> void {
        dis[u] = d;
        for (int& i : adj[u])
            if (i != p)
                dfs(i, u, d + 1, dfs);
    };
    dfs(0, -1, 0, dfs);
    int a = max_element(dis.begin(), dis.end()) - dis.begin();
    dfs(a, -1, 0, dfs);
    int b = max_element(dis.begin(), dis.end()) - dis.begin();

    v<int> path;
    auto go = [&](int u, int p, auto&& go) -> bool {
        path.push_back(u);
        if (u == b) return 1;
        bool x = 0;
        for (int& i : adj[u])
            if (i != p)
                if (go(i, u, go)) {
                    x = 1;
                    break;
                }
        if (not x)
            path.pop_back();
        return x;
    };
    go(a, -1, go);

    v<int> vis(n);
    for (int& x : path)
        vis[x] = 1;

    int c = 0, best = 0;
    if (a == c or b == c) c++;    
    if (a == c or b == c) c++;

    auto find = [&](int u, int d, auto&& find) -> void {
        if (vis[u]) return;
        vis[u] = 1;
        if (d > best) best = d, c = u;
        for (int& i : adj[u])
            if (not vis[i])
                find(i, d + 1, find);
    };
    for (int& x : path) {
        vis[x] = 0;
        find(x, 0, find);
    }

    cout << dis[b] + best << nl;
    cout << a + 1 << " " << b + 1 << " " << c + 1 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}