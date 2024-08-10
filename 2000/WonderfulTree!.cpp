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
    for (int i = 1; i < n; i++) {
        int u; cin >> u; u--;
        adj[i].push_back(u);
        adj[u].push_back(i);
    }

    v<int> lz(n);
    auto fix = [&](int u, int p, auto&& fix) -> void {
        for (int& i : adj[u]) if (i != p) {
            fix(i, u, fix);
            a[u] += lz[i];
            lz[u] += lz[i];
        }
    };

    int ans = 0;
    auto dfs = [&](int u, int p, auto&& dfs) -> void {
        int x = 0;
        for (int& i : adj[u]) if (i != p) {
            dfs(i, u, dfs);
            x += a[i];
        }
        if (a[u] <= x) return;

        int need = a[u] - x;
        queue<array<int, 3>> q;
        fill(lz.begin(), lz.end(), 0ll);
        for (int& i : adj[u]) if (i != p)
            q.push({i, u, 1});
        
        while (q.size() and need) {
            auto [i, in_p, d] = q.front();
            q.pop();

            int y = 0;
            bool ok = 0;
            for (int& j : adj[i])
                if (j != in_p) {
                    y += a[j];
                    ok = 1;
                }
            if (ok == 0) {
                a[i] += need;
                lz[i] += need;
                ans += need * d;
                need = 0;
            }
            else {
                int sub = min(y - a[i], need);
                need -= sub;
                a[i] += sub;
                lz[i] += sub;
                ans += sub * d;
            }

            for (int& j : adj[i])
                if (j != in_p)
                    q.push({j, i, d + 1});
        }
        for (int& i : adj[u])
            if (i != p)
                fix(i, u, fix);
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