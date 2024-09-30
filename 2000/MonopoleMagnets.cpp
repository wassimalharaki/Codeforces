#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

v<int> dx{-1, 0, 1, 0};
v<int> dy{0, -1, 0, 1};

void solve() {
    int n, m; cin >> n >> m;

    v a(n, v<int>(m));
    for (auto& x : a)
        for (auto& y : x) {
            char c; cin >> c;
            y = c == '#';
        }
    
    for (int i = 0; i < n; i++) {
        v<int> b{a[i][0]};
        for (int j = 1; j < m; j++)
            if (a[i][j] != a[i][j - 1])
                b.push_back(a[i][j - 1]);
        for (int j = 0; j < (int) b.size() - 2; j++)
            if (b[j] == 1 and b[j + 1] == 0 and b[j + 2] == 1) {
                cout << - 1 << nl;
                return;
            }
    }

    for (int j = 0; j < m; j++) {
        v<int> b{a[0][j]};
        for (int i = 1; i < n; i++)
            if (a[i][j] != a[i - 1][j])
                b.push_back(a[i][j]);
        
        for (int i = 0; i < (int) b.size() - 2; i++)
            if (b[i] == 1 and b[i + 1] == 0 and b[i + 2] == 1) {
                cout << - 1 << nl;
                return;
            }
    }

    int br = 0, bc = 0;
    for (int i = 0; i < n; i++) {
        bool ok = 1;
        for (int j = 0; j < m; j++)
            ok &= a[i][j] == 0;
        br += ok;
    }

    for (int j = 0; j < m; j++) {
        bool ok = 1;
        for (int i = 0; i < n; i++)
            ok &= a[i][j] == 0;
        bc += ok;
    }

    if ((br and not bc) or (bc and not br)) {
        cout << -1 << nl;
        return;
    }

    auto valid = [&](int i, int j) -> bool {
        return i >= 0 and j >= 0 and i < n and j < m and a[i][j];
    };

    v vis(n, v<int>(m));
    auto dfs = [&](int i, int j, auto&& dfs) -> void {
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int r = i + dx[k], c = j + dy[k];
            if (not valid(r, c)) continue;
            if (vis[r][c]) continue;
            dfs(r, c, dfs);
        }
    };

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (not vis[i][j] and valid(i, j)) {
                ans++;
                dfs(i, j, dfs);
            }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}