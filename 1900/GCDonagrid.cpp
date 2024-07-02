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

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> nums(n, v<int>(m));
    for (auto& a : nums)
        for (auto& b : a)
            cin >> b;

    v<v<v<int>>> dp(n, v<v<int>>(m));
    dp[0][0].push_back(nums[0][0]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            sort(dp[i][j].begin(), dp[i][j].end());
            dp[i][j].resize(unique(dp[i][j].begin(), dp[i][j].end()) - dp[i][j].begin());

            v<int> clean;
            for (int l = 0; l < dp[i][j].size(); l++) {
                bool ok = 1;
                for (int r = l + 1; r < dp[i][j].size(); r++)
                    if (dp[i][j][r] % dp[i][j][l] == 0) {
                        ok = 0;
                        break;
                    }
                if (ok)
                    clean.push_back(dp[i][j][l]);
            }
            dp[i][j].swap(clean);

            if (i + 1 < n)
                for (int& x : dp[i][j])
                    dp[i + 1][j].push_back(gcd(x, nums[i + 1][j]));
            if (j + 1 < m)
                for (int& x : dp[i][j])
                    dp[i][j + 1].push_back(gcd(x, nums[i][j + 1]));
        }
    cout << dp[n - 1][m - 1].back() << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}