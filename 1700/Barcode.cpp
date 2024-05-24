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
    int n, m, x, y; 
    cin >> n >> m >> x >> y;
    
    v<array<int, 2>> a(m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            a[j][0] += c == '.';
            a[j][1] += c == '#';
        }

    v<array<int, 2>> dp(m + 1, {INT_MAX, INT_MAX});
    dp[0] = {0, 0};
    for (int i = 1; i <= m; i++) {
        if (i - x < 0) continue;
        array<int, 2> b{0, 0};
        for (int j = i - x + 1; j < i; j++) {
            b[0] += a[j][1];
            b[1] += a[j][0];
        }
        for (int j = i - x; i - j <= y and j >= 0; j--) {
            b[0] += a[j][1];
            b[1] += a[j][0];
            dp[i][0] = min(dp[i][0], b[0] + dp[j][1]);
            dp[i][1] = min(dp[i][1], b[1] + dp[j][0]);
        }
    }
    cout << min(dp[m][0], dp[m][1]) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}