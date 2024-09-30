#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, k; cin >> n >> k;

    v<int> a(n);
    for (int& x : a) cin >> x;

    auto check = [&](int x) -> bool {
        {
            v<int> dp(n);
            dp[0] = 0; dp[1] = a[1] <= x;
            for (int i = 2; i < n; i++)
                dp[i] = max(dp[i - 1], dp[i - 2] + (a[i] <= x));
            if (dp[n - 1 - (k & 1)] >= k / 2) return 1;
        }
        {
            v<int> dp(n);
            dp[0] = a[0] <= x; dp[1] = a[0] <= x or a[1] <= x;
            for (int i = 2; i < n; i++)
                dp[i] = max(dp[i - 1], dp[i - 2] + (a[i] <= x));
            if (dp[n - 1 - (k & 1 ^ 1)]>= (k + 1) / 2) return 1;
        }
        return 0;
    };

    int lo = 1, hi = 1e9, ans = 1e9;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (check(mid))
            hi = mid - 1, ans = mid;
        else
            lo = mid + 1;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}