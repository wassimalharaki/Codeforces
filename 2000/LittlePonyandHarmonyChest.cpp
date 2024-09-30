#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

const int N = 16;

v<int> b{
    2, 3, 5, 7, 11, 13,
    17, 19, 23, 29, 31,
    37, 41, 43, 47, 53
}, p{
    5, 3, 2, 2,
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1,
};

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<v<array<int, 2>>> adj(1 << N);
    {
        int i = 0, m = 0, x = 1;
        auto f = [&](int j, auto&& f) -> void {
            if (x >= 59)
                return;
            
            if (j == N) {
                adj[i].push_back({m, x});
                return;
            }

            f(j + 1, f);
            if (!((1 << j) & i))
                return;

            int prev = x;
            m += (1 << j);
            for (int k = 1; k <= p[j]; k++) {
                x *= b[j];
                f(j + 1, f);
            }
            m -= (1 << j);
            x = prev;
        };
        for (; i < (1 << N); i++)
            f(0, f);
    }

    v dp(n + 1, v<array<int, 3>>(1 << N, {INT_MAX, -1, -1}));
    fill(dp[0].begin(), dp[0].end(), array<int, 3>{0, -1, -1});

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < (1 << N); j++)
            for (auto& [k, x] : adj[j]) {
                int y = abs(a[i - 1] - x) + dp[i - 1][j ^ k][0];
                if (y < dp[i][j][0]) {
                    dp[i][j][0] = y;
                    dp[i][j][1] = x;
                    dp[i][j][2] = j ^ k;
                }
            }
    
    v<int> ans(n);
    for (int i = n, j = (1 << N) - 1; i; i--) {
        ans[i - 1] = dp[i][j][1];
        j = dp[i][j][2];
    }

    for (int& x : ans)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}