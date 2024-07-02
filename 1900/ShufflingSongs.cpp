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

int ppcnt(int i) {
    return __builtin_popcountll(i);
}

void solve() {
    int n; cin >> n;

    int k = 0;
    map<string, int> ids;
    v<array<int, 2>> nums(n);
    for (int i = 0; i < n; i++) {
        string s, t; cin >> s >> t;
        if (not ids.count(s))
            ids[s] = k++;
        if (not ids.count(t))
            ids[t] = k++;
        nums[i] = {ids[s], ids[t]};
    }

    v<v<bool>> adj(n, v<bool>(n));
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            adj[i][j] = adj[j][i] =
                ((nums[i][0] == nums[j][0]) or
                 (nums[i][1] == nums[j][1]));

    v<v<bool>> dp(1 << n, v<bool>(n));
    for (int i = 0; i < n; i++)
        dp[1 << i][i] = 1;

    for (int mask = 1; mask < (1 << n); mask++)
        if (ppcnt(mask) != 1)
            for (int i = 0; i < n; i++)
                if (mask & (1 << i))
                    for (int j = 0; j < n; j++)
                        if (dp[mask ^ (1 << i)][j] and adj[i][j])
                            dp[mask][i] = 1;

    int ans = n - 1;
    for (int i = 0; i < (1 << n); i++)
        if (*max_element(dp[i].begin(), dp[i].end()))
            ans = min(ans, n - ppcnt(i));
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}