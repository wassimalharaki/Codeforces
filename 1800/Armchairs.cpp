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
    int n, m; cin >> n;

    v<int> o, z;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        x ? o.push_back(i) : z.push_back(i);
    }
    
    v dp(o.size() + 1, v<int>(z.size() + 1, 1e9));
    fill(dp[0].begin(), dp[0].end(), 0ll);
    for (int i = 1; i <= o.size(); i++)
        for (int j = i; j <= z.size(); j++)
            dp[i][j] = min({
                dp[i][j], 
                dp[i][j - 1],
                abs(o[i - 1] - z[j - 1]) + dp[i - 1][j - 1]
            });
    cout << dp[o.size()][z.size()] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}