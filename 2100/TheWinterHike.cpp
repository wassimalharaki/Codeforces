#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

using ai2 = array<int, 2>;
using ai3 = array<int, 3>;
v<int> dx{-1, 0, 1, 0};
v<int> dy{0, -1, 0, 1};

void solve() {
    int n; cin >> n;

    v a(2 * n, v<int>(2 * n));
    for (auto& x : a)
        for (int& y : x)
            cin >> y;

    auto valid = [&](int i, int j) {
        return i >= 0 and j >= 0 and (i >= n or j >= n)
            and i < 2 * n and j < 2 * n;
    };

    auto get = [&](int i, int j) {
        v<ai2> adj;
        for (int k = 0; k < 4; k++) {
            int r = (i + dx[k] + 2 * n) % (2 * n);
            int c = (j + dy[k] + 2 * n) % (2 * n);
            if (valid(r, c))
                adj.push_back({r, c});
        }
        return adj;
    };

    priority_queue<ai3, v<ai3>, greater<ai3>> pq;
    v d(2 * n, v<int>(2 * n, LLONG_MAX)), vis(2 * n, v<int>(2 * n));
    for (int i : {0ll, n - 1})
        for (int j : {0ll, n - 1}) {
            d[i][j] = 0;
            pq.push({0, i, j});
        }
    
    while (pq.size()) {
        auto [w, i, j] = pq.top();
        pq.pop();
        if (vis[i][j]) continue;
        vis[i][j] = 1;

        for (auto& [r, c] : get(i, j))
            if (w + a[r][c] < d[r][c]) {
                d[r][c] = w + a[r][c];
                pq.push({d[r][c], r, c});
            }
    }

    int ans = 0, x = LLONG_MAX;
    for (int i = n; i < 2 * n; i++)
        for (int j = n; j < 2 * n; j++) {
            x = min(x, d[i][j] - a[i][j]);
            ans += a[i][j];
        }
    cout << ans + x << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}