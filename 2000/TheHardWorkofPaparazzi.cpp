#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

using ai2 = array<int, 2>;

void solve() {
    int r, n; cin >> r >> n;

    auto get = [&](ai2& x, ai2& y) -> int {
        return abs(x[0] - y[0]) + abs(x[1] - y[1]);
    };

    v<ai2> a(n + 1); a[0] = {1, 1};
    v<int> dp(n + 1, INT_MIN), b(n + 1), pref(n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        cin >> a[i][0] >> a[i][1];
        for (int j = i - 1; j >= max(0, i - 2 * r); j--)
            if (b[j] + get(a[j], a[i]) <= b[i])
                dp[i] = max(dp[i], 1 + dp[j]);
        if (i - 2 * r >= 0)
            dp[i] = max(dp[i], 1 + pref[i - 2 * r]);
        pref[i] = max(pref[i - 1], dp[i]);
    }
    cout << *max_element(dp.begin(), dp.end()) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}