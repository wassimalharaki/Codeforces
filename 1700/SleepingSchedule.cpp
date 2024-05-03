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

void cmax(int& a, int b) {
    a = max(a, b);
}

void solve() {
    int n, h, l, r;
    cin >> n >> h >> l >> r;

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    v<v<int>> dp(n + 1, v<int>(h, INT_MIN));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int x = nums[i - 1];
        for (int j = 0; j < h; j++, x++) {
            cmax(dp[i][x % h], dp[i - 1][j] + (l <= x % h and x % h <= r));
            cmax(dp[i][(x - 1) % h], dp[i - 1][j] + (l <= (x - 1) % h and (x - 1) % h <= r));
        }
    }
    cout << *max_element(dp[n].begin(), dp[n].end());
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}