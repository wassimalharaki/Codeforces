#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, m; cin >> n >> m;

    v<v<char>> nums(n, v<char>(m));
    for (auto& a : nums)
        for (auto& b : a)
            cin >> b;
    
    bool ok = 1;
    array<int, 4> dx{1, 0, -1, 0};
    array<int, 4> dy{0, -1, 0, 1};
    v<v<bool>> vis(n, v<bool>(m));

    auto valid = [&](int i, int j) {
        return i >= 0 and j >= 0 and i < n and j < m;
    };

    auto out = [&](int i, int j) {
        return i == n - 1 and j == m - 1;
    };

    auto dfs_bad = [&](int i, int j, auto&& dfs_bad) -> void {
        vis[i][j] = 1;
        if (out(i, j)) ok = 0;
        for (int k = 0; k < 4; k++) {
            int r = i + dx[k];
            int c = j + dy[k];

            if (not valid(r, c)) continue;
            if (vis[r][c]) continue;

            if (nums[r][c] == '.')
                nums[r][c] = '#';
            else if (nums[r][c] != '#')
                dfs_bad(r, c, dfs_bad);
        }
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (nums[i][j] == 'B' and not vis[i][j])
                dfs_bad(i, j, dfs_bad);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            vis[i][j] = 0;

    bool check = 0;
    auto dfs_good = [&](int i, int j, auto&& dfs_good) -> void {
        vis[i][j] = 1;
        if (out(i, j)) check = 1;
        for (int k = 0; k < 4; k++) {
            int r = i + dx[k];
            int c = j + dy[k];

            if (not valid(r, c)) continue;
            if (vis[r][c]) continue;

            if (nums[r][c] != '#')
                dfs_good(r, c, dfs_good);
        }
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (nums[i][j] == 'G' and not vis[i][j]) {
                check = 0;
                dfs_good(i, j, dfs_good);
                ok &= check;
            }

    cout << (ok ? "Yes" : "No") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}