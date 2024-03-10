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
    int n; cin >> n;


    v<v<int>> adj(n + 1);
    v<array<int, 3>> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        edges[i] = {a, b, i};
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    sort(all(edges));

    if (n == 2) {
        cout << 0;
        return;
    }

    int cnt = 0;
    v<int> ans(n - 1, -1);
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() != 1)
            continue;
        int a = i, b = adj[i][0];
        if (a > b) swap(a, b);
        auto it = lower_bound(all(edges), array<int, 3>{a, b, -1});
        ans[(*it)[2]] = cnt++;
    }

    for (int i = 0; i < n - 1; i++)
        if (ans[i] == -1)
            ans[i] = cnt++;
    
    for (int& a : ans) cout << a << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}