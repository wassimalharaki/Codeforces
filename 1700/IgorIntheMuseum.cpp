#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

v<int> dx{1, 0, -1, 0};
v<int> dy{0, -1, 0, 1};

void solve() {
    int n, m, q; cin >> n >> m >> q;

    v<v<int>> a(n, v<int>(m));
    for (auto& x : a)
        for (int& y : x) {
            char c; cin >> c;
            y = c == '.';
        }

    auto valid = [&](int i, int j) {
        return i >= 0 and j >= 0 and i < n and j < m;
    };
    
    v<v<int>> vis, comp_id;
    vis = comp_id = v<v<int>>(n, v<int>(m));
    v<int> comps;
    
    auto dfs = [&](int i, int j, auto&& dfs) -> void {
        vis[i][j] = 1;
        comp_id[i][j] = comps.size() - 1;

        for (int k = 0; k < 4; k++) {
            int r = i + dx[k];
            int c = j + dy[k];

            if (not valid(r, c) or vis[r][c]) continue;
            if (a[r][c] == 0)
                comps.back()++;
            else
                dfs(r, c, dfs);
        }
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (not vis[i][j] and a[i][j]) {
                comps.push_back(0);
                dfs(i, j, dfs);
            }
    
    while (q--) {
        int i, j; cin >> i >> j;
        cout << comps[comp_id[i - 1][j - 1]] << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}