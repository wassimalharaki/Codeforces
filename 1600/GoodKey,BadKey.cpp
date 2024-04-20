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

const int N = 31;

int get(int a, int x) {
    return x >= N ? 0 : a / (1 << x);
}

void solve() {
    int n, k; cin >> n >> k;

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    v<array<int, N>> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + nums[i - 1] - k;
        for (int x = 1; x < N; x++) {
            int a = dp[i - 1][x] + get(nums[i - 1], x) - k;
            int b = dp[i - 1][x - 1] + get(nums[i - 1], x);
            dp[i][x] = max(a, b);
        }
        dp[i][N - 1] = max(dp[i][N - 1], dp[i - 1][N - 1]);
    }
    cout << *max_element(dp[n].begin(), dp[n].end()) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}