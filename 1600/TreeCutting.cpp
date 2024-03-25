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
    int n, k; cin >> n >> k;

    v<v<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int x = 0, y = 0;
    v<int> count(n + 1);
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        count[u]++;
        for (int& i : adj[u]) {
            if (i == p) continue;
            dfs(i, u, dfs);
            if (x == 3) dbg(i, count[i]);
            if (count[i] >= x)
                y++;
            else
                count[u] += count[i];
        }
    };

    int lo = 0, hi = 2e5, ans;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        x = mid; y = 0;
        fill(all(count), 0ll);
        dfs(1, -1, dfs);
        if (count[1] < x) y--;

        if (y >= k)
            lo = mid + 1, ans = mid;
        else
            hi = mid - 1;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}