#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<v<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int ans = 0;
    auto dfs = [&](int u, int p, auto&& dfs) -> map<int, int> {
        map<int, int> me;

        for (int& i : adj[u])
            if (i != p) {
                auto him = dfs(i, u, dfs);
                if (him.size() > me.size())
                    me.swap(him);
                for (auto& [c, x] : him) {
                    if (c != a[u])
                        ans += x * me[c];
                    me[c] += x;
                }
            }

        ans += me[a[u]];
        me[a[u]] = 1;
        return me;
    };
    dfs(0, -1, dfs);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}