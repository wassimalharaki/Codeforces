#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

v<int> dx{-1, 0, 1, 0};
v<int> dy{0, -1, 0, 1};

void solve() {
    int n, m, t; cin >> n >> m >> t;

    v a(n, v<int>(m));
    for (auto& x : a) {
        for (int i = 0; i < m; i++) {
            char c; cin >> c;
            x[i] = c - '0';
        }
    }

    auto valid = [&](int i, int j) -> bool {
        return i >= 0 and j >= 0 and i < n and j < m;
    };

    auto adj = [&](int i, int j) -> v<array<int, 2>> {
        v<array<int, 2>> x;
        for (int k = 0; k < 4; k++) {
            int r = i + dx[k], c = j + dy[k];
            if (valid(r, c))
                x.push_back({r, c});
        }
        return x;
    };

    int sz = 0;
    queue<array<int, 2>> q;
    v vis(n, v<int>(m)), b(n, v<int>(m, -1));
    auto dfs = [&](int i, int j, auto&& dfs) -> void {
        sz++;
        vis[i][j] = 1;
        for (auto& [r, c] : adj(i, j))
            if (not vis[r][c] and a[r][c] == a[i][j])
                dfs(r, c, dfs);
        if (sz >= 2) {
            q.push({i, j});
            b[i][j] = 0;
        }
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (not vis[i][j])
                sz = 0, dfs(i, j, dfs);
    
    while (q.size()) {
        auto [i, j] = q.front();
        q.pop();

        for (auto& [r, c] : adj(i, j))
            if (b[r][c] == -1 and a[r][c] != a[i][j]) {
                vis[r][c] = 1;
                b[r][c] = b[i][j] + 1;
                q.push({r, c});
            }
    }

    while (t--) {
        int i, j; cin >> i >> j;
        int64_t p; cin >> p;
        i--, j--;

        if (b[i][j] == -1 or p <= b[i][j])
            cout << a[i][j] << nl;
        else
            cout << ((p - b[i][j]) & 1 ? !a[i][j] : a[i][j]) << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}