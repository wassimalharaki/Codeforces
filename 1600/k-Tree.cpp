#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

const int mod = 1e9 + 7;

int f(int n, int k) {
    if (k == 0) return 0;
    v<int> dp(n + k), nums(k);
    iota(all(nums), 1ll); dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int& a : nums)
            dp[i + a] = (dp[i + a] + dp[i]) % mod;
    return dp[n];
}

void solve() {
    int n, k, d; cin >> n >> k >> d;
    int x = f(n, k) - f(n, d - 1);
    cout << (x + mod) % mod;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}