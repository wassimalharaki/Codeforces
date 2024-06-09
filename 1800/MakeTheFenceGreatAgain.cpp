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

const int N = 10;

void solve() {
    int n; cin >> n;

    v<array<int, 2>> a(n);
    for (auto& x : a)
        cin >> x[0] >> x[1];

    v<array<int, N>> dp(n);
    for (int i = 0; i < N; i++)
        dp[0][i] = a[0][1] * i;

    for (int i = 1; i < n; i++) {
        dp[i].fill(1e18);
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                if (a[i][0] + j != a[i - 1][0] + k)
                    dp[i][j] = min(dp[i][j], j * a[i][1] + dp[i - 1][k]);
    }
    cout << *min_element(dp.back().begin(), dp.back().end()) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}