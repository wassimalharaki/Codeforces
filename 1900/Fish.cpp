#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v a(n, v<double>(n));
    for (auto& x : a)
        for (auto& y : x)
            cin >> y;
    
    v<double> dp(1 << n, -1); dp[(1 << n) - 1] = 1;
    auto go = [&](int mask, auto&& go) -> double {
        if (dp[mask] > -0.5) return dp[mask];
        dp[mask] = 0;
        int y = __builtin_popcountll(mask);
        int x = (y + 1) * y / 2;
        for (int i = 0; i < n; i++)
            if (!(mask & (1 << i)))
                for (int j = 0; j < n; j++)
                    if (mask & (1 << j))
                        dp[mask] += go(mask ^ (1 << i), go) / x * a[j][i];
        return dp[mask];
    };

    for (int i = 0; i < n; i++)
        cout << fixed << setprecision(6) << go(1 << i, go) << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}