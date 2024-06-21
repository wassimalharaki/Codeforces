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
    int n, k, p; cin >> n >> k >> p;

    v<int> a(n), b(k);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    v dp(n + 1, v<int>(k + 1));
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= k; j++)
            dp[i][j] = max(abs(a[i - 1] - b[j - 1]) + abs(p - b[j - 1]), dp[i - 1][j - 1]);
    cout << *min_element(dp[n].begin() + n, dp[n].end()) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}