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

const int N = 400;

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());

    v dp(n + 1, v<int>(N + 1, 1e9));
    fill(dp[0].begin(), dp[0].end(), 0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 0; k < j; k++)
                dp[i][j] = min(dp[i][j], abs(a[i - 1] - j) + dp[i - 1][k]);
    cout << *min_element(dp[n].begin(), dp[n].end()) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}