#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    v<set<array<int, 2>>> adj(n);
    for (int i = 0; i < n; i++)
        adj[i].insert({-1, 0});

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;

        auto it = --adj[a].lower_bound({c, -1});
        int cnt = (*it)[1] + 1;

        it = --adj[b].upper_bound({c, INT_MAX});
        if ((*it)[1] >= cnt) continue;
        if ((*it)[0] == c) {
            adj[b].erase(it);
            it = --adj[b].lower_bound({c, -1});
        }
        adj[b].insert({c, cnt});
        while (1) {
            it = adj[b].lower_bound({c, INT_MAX});
            if (it == adj[b].end() or (*it)[1] > cnt)
                break;
            adj[b].erase(it);
        }
    }

    int ans = 0;
    for (auto& x : adj)
        for (auto& [y, z] : x)
            ans = max(ans, z);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}