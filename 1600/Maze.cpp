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
    int n, m, k; cin >> n >> m >> k;

    v<v<char>> grid(n, v<char>(m));
    int cnt = 0;
    for (auto& a : grid)
        for (auto& b : a) {
            cin >> b;
            cnt += b == '.';
        }

    v<int> dx{1, 0, -1, 0};
    v<int> dy{0, 1, 0, -1};
    auto valid = [&](int r, int c) {
        return r >= 0 and c >= 0 and r < n and c < m;
    };

    int r, c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == '.')
                r = i, c = j;
    
    set<array<int, 2>> have;
    auto dfs = [&](int i, int j, auto&& dfs) -> void {
        if (have.size() == cnt - k) return;
        if (have.count({i, j})) return;
        have.insert({i, j});
        for (int l = 0; l < 4; l++) {
            int nr = i + dx[l], nc = j + dy[l];
            if (not valid(nr, nc)) continue;
            if (grid[nr][nc] != '.') continue;
            dfs(nr, nc, dfs);
        }
    };
    dfs(r, c, dfs);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == '.')
                if (not have.count({i, j}))
                    grid[i][j] = 'X';

    for (auto& a : grid) {
        for (auto& b : a)
            cout << b;
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}