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
    int n, m, k; cin >> n >> m >> k;

    v horz(n, v<int>(m - 1)), vert(n - 1, v<int>(m));
    for (auto& x : horz)
        for (auto& y : x)
            cin >> y;
    
    for (auto& x : vert)
        for (auto& y : x)
            cin >> y;

    auto valid = [&](int r, int c) -> bool {
        return r >= 0 and c >= 0 and r < n and c < m;
    };

    v dp(k + 1, v(n, v<int>(m, 1e9)));
    for (auto& x : dp[0])
        for (auto& y : x)
            y = 0;
    
    for (int l = 2; l <= k; l += 2)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int o = 0; o < 4; o++) {
                    int r = i + dx[o], c = j + dy[o];
                    if (not valid(r, c)) continue;

                    int x;
                    if (r == i)
                        x = horz[i][min(j, c)];
                    else
                        x = vert[min(i, r)][j];

                    dp[l][i][j] = min(dp[l][i][j], dp[l - 2][r][c] + 2 * x);
                }

    for (auto& x : dp[k]) {
        for (auto& y : x)
            cout << (y == 1e9 ? -1 : y) << " ";
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