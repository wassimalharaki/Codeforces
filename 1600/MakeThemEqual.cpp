#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

const int N = 1e3 + 1;
v<int> pre(N, INT_MAX);

void solve() {
    int n, k; cin >> n >> k;

    v<int> cost(n), reward(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        cost[i] = pre[a];
    }
    for (int& a : reward) cin >> a;

    if (k >= accumulate(all(cost), 0ll)) {
        cout << accumulate(all(reward), 0ll) << nl;
        return;
    }

    v<v<int>> dp(n + 1, v<int>(k + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++)
            if (j - cost[i - 1] >= 0)
                dp[i][j] = max(dp[i - 1][j], reward[i - 1] + dp[i - 1][j - cost[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
    cout << dp[n][k] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pre[0] = pre[1] = 0;
    for (int i = 2; i < N; i++) {
        for (int j = (i + 1) / 2; j < i; j++) {
            int need = i - j;
            int x = j / need;
            if (j / x != need) continue;
            pre[i] = min(pre[i], pre[j] + 1);
        }
    }

    int T = 1;
    cin >> T;
    while (T--) solve();
}