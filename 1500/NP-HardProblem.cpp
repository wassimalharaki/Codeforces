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

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> adj(n + 1);
    bool ok = 1;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    set<int> left, right;
    v<int> vis(n + 1);
    auto dfs = [&](int u, bool alt, auto&& dfs) -> void {
        vis[u] = 1;
        if (alt) 
            left.insert(u);
        else
            right.insert(u);

        for (int& i : adj[u])
            if (alt) {
                if (left.count(i)) {
                    ok = 0;
                    return;
                }
                if (not right.count(i)) {
                    right.insert(i);
                    dfs(i, !alt, dfs);
                }
            }
            else {
                if (right.count(i)) {
                    ok = 0;
                    return;
                }
                if (not left.count(i)) {
                    left.insert(i);
                    dfs(i, !alt, dfs);
                }
            }
    };
    for (int i = 1; i <= n; i++)
        if (not vis[i])
            dfs(i, 1, dfs);

    if (not ok) {
        cout << -1;
        return;
    }

    cout << left.size() << nl;
    for (int a : left) cout << a << " ";
    cout << nl << right.size() << nl;
    for (int a : right) cout << a << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}