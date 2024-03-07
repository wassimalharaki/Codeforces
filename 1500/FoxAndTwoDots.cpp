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

using pii = pair<int, int>;

void solve() {
    int n, m; cin >> n >> m;

    v<string> grid(n);
    for (string& s : grid) cin >> s;

    v<v<bool>> vis(n, v<bool>(m));
    v<int> dx{1, 0, -1, 0};
    v<int> dy{0, 1, 0, -1};
    bool ok = 0;

    auto valid = [&](pii& q) {
        int r = q.first, c = q.second;
        return r >= 0 and c >= 0 and r < n and c < m;
    };

    auto dfs = [&](pii u, pii p, auto&& dfs) -> void {
        int r = u.first, c = u.second;
        vis[r][c] = 1;
        for (int i = 0; i < 4; i++) {
            pii q{r + dx[i], c + dy[i]};
            if (not valid(q)) continue;
            if (q == p) continue;
            if (grid[q.first][q.second] != grid[r][c]) continue;
            if (vis[q.first][q.second]) ok = 1;
            else dfs(q, u, dfs);
        }
    };
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (not vis[i][j])
                dfs({i, j}, {-1, -1}, dfs);

    cout << (ok ? "Yes" : "No");
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}