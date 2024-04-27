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
    string s; cin >> s;
    int n = s.size();

    v<v<int>> dp(n, v<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (s[i] == s[j] or s[i] == '?' or s[j] == '?') {
                dp[i][j] = 1;
                if (i - 1 >= 0 and j - 1 >= 0)
                    dp[i][j] += dp[i - 1][j - 1];
            }
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j - dp[i][j])
                ans = max(ans, 2 * dp[i][j]);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}