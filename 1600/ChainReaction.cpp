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

const int N = 1e6 + 2;
int have[N], dp[N];

void solve() {
    memset(have, 0, sizeof(have));
    memset(dp, 0, sizeof(dp));

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int x, k; cin >> x >> k;
        have[++x] = k;
    }

    for (int i = 1; i < N; i++)
        if (have[i])
            dp[i] = 1 + dp[max(0ll, i - have[i] - 1)];
        else
            dp[i] = dp[i - 1];

    cout << n - *max_element(dp, dp + N) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}