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

using ai2 = array<int, 2>;
using ai4 = array<int, 4>;

v<int> dx{-1, 1, 0, 0};
v<int> dy{0, 0, -1, 1};

void solve() {
    int n, m; cin >> n >> m;
    ai2 src; cin >> src[0] >> src[1];
    ai2 lr; cin >> lr[0] >> lr[1];

    v a(n, v<int>(m));
    for (auto& x : a)
        for (auto& y : x) {
            char c; cin >> c;
            y = c == '.';
        }

    auto valid = [&](int r, int c) -> bool {
        return r >= 0 and c >= 0 and r < n and c < m;
    };

    int ans = 1;
    v vis(n, v<int>(m));
    vis[--src[0]][--src[1]] = 1;
    priority_queue<ai4, v<ai4>, less<ai4>> pq;
    pq.push({lr[0], lr[1], src[0], src[1]});

    while (pq.size()) {
        auto [x, y, i, j] = pq.top();
        pq.pop();

        for (int k = 0; k < 4; k++) {
            int r = i + dx[k], c = j + dy[k];
            if (not valid(r, c) or not a[r][c] or vis[r][c])
                continue;
            if (x - max(0ll, j - c) < 0 or y - max(0ll, c - j) < 0)
                continue;

            ans++;
            vis[r][c] = 1;
            pq.push({x - max(0ll, j - c), y - max(0ll, c - j), r, c});
        }
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