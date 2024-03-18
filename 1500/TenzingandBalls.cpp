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

void solve() {
    int n; cin >> n;
    
    v<int> vals(n + 1, -1), dp(n + 1);
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        dp[i] = max(dp[i - 1], vals[a] - n + i + 1);
        vals[a] = max(vals[a], dp[i - 1] + n - i);
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