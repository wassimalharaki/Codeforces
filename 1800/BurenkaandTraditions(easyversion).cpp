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

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    int x = 0;
    map<int, int> have{{0, -1}};
    v<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        x ^= a[i - 1];
        dp[i] = 1 + dp[i - 1];
        if (have.count(x)) {
            dp[i] = min(dp[i], i + have[x]);
            have[x] = min(have[x], dp[i] - i - 1);
        }
        else
            have[x] = dp[i] - i - 1;
    }
    cout << dp[n] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}