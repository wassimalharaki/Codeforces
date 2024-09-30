#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> grid(n, v<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    
    auto get = [&](int r, int c, int shift) {
        r = ((r + shift) % n + n) % n;
        return grid[r][c];
    };

    int ans = LONG_LONG_MAX;
    queue<array<int, 3>> q;
    set<array<int, 2>> vis;
    q.push({0, 0, 0});

    while (not q.empty()) {
        int r = q.front()[0];
        int c = q.front()[1];
        int w = q.front()[2];
        q.pop();

        if (c == m - 1) {
            r = (r % n + n) % n;
            ans = min(ans, w + min(r + 1, n - 1 - r));
            continue;
        }

        if (vis.count({(r % n + n) % n, c})) continue;
        else vis.insert({(r % n + n) % n, c});

        if (get(r, c + 1, w + 1) == 0)
            q.push({r, c + 1, w + 1});
        if (get(r + 1, c, w + 1) == 0 and get(r, c, w + 1) == 0)
            q.push({r + 1, c, w + 1});
    }
    cout << (ans == LONG_LONG_MAX ? -1 : ans) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}