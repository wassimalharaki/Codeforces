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

const int N = 1e5 + 1;
const int mod = 1e9 + 7;

void solve() {
    int t, k; cin >> t >> k;

    v<int> dp(N), prefix(N);
    fill(dp.begin(), dp.begin() + k, 1);
    iota(prefix.begin(), prefix.begin() + k, 1);
    for (int i = k; i < N; i++) {
        dp[i] = (dp[i - k] + dp[i - 1]) % mod;
        prefix[i] = (prefix[i - 1] + dp[i]) % mod;
    }

    while (t--) {
        int a, b; cin >> a >> b;
        cout << (prefix[b] - prefix[a - 1] + mod) % mod << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}