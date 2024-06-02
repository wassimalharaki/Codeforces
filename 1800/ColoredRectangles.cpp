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
    int n, m, o; cin >> n >> m >> o;

    v<int> a(n), b(m), c(o);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    for (int& x : c) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    v dp = v(n + 1, v(m + 1, v<int>(o + 1, -1)));
    auto go = [&](int i, int j, int k, auto&& go) -> int {
        int cnt = (i == 0) + (j == 0) + (k == 0);
        if (cnt >= 2) return 0;
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        if (i and j)
            dp[i][j][k] = max(dp[i][j][k], a[i - 1] * b[j - 1] + go(i - 1, j - 1, k, go));
        if (i and k)
            dp[i][j][k] = max(dp[i][j][k], a[i - 1] * c[k - 1] + go(i - 1, j, k - 1, go));
        if (j and k)
            dp[i][j][k] = max(dp[i][j][k], b[j - 1] * c[k - 1] + go(i, j - 1, k - 1, go));
        return dp[i][j][k];
    };
    cout << go(n, m, o, go);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}