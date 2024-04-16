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

    v<v<int>> adj(n + 1, v<int>(n + 1, -1));
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a][b] = adj[b][a] = 1;
    }

    int x = INT_MAX;
    {
        v<bool> vis(n + 1);
        queue<array<int, 2>> q;
        q.push({1, 0});
        vis[0] = 1;
        while (q.size()) {
            auto [u, d] = q.front();
            q.pop();

            if (u == n) {
                x = d;
                break;
            }

            for (int i = 1; i <= n; i++) {
                if (adj[u][i] == 1) continue;
                if (vis[i]) continue;
                q.push({i, d + 1});
                vis[i] = 1;
            }
        }
    }

    int y = INT_MAX;
    {
        v<bool> vis(n + 1);
        queue<array<int, 2>> q;
        q.push({1, 0});
        vis[0] = 1;
        while (q.size()) {
            auto [u, d] = q.front();
            q.pop();

            if (u == n) {
                y = d;
                break;
            }

            for (int i = 1; i <= n; i++) {
                if (adj[u][i] == -1) continue;
                if (vis[i]) continue;
                q.push({i, d + 1});
                vis[i] = 1;
            }
        }
    }
    
    x = max(x, y);
    cout << (x == INT_MAX ? -1 : x);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}