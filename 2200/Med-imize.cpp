#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, k; cin >> n >> k;

    v<int> a(n);
    for (int& x : a) cin >> x;

    if (k >= n) {
        sort(a.begin(), a.end());
        cout << a[(n - 1) / 2] << nl;
        return;
    }

    if (k == 1) {
        sort(a.begin(), a.end());
        cout << a.back() << nl;
        return;
    }

    auto check = [&](int x) -> bool {
        v<int> dp(k, -1e9);
        for (int i = 0; i < n; i++)
            if (i % k == 0)
                dp[0] = max(dp[0], (int) (a[i] >= x ? 1 : -1));
            else
                dp[i % k] = max(dp[i % k], dp[i % k - 1] + (a[i] >= x ? 1 : -1));
        return dp[((n % k - 1) + k) % k] > 0;
    };

    int lo = 1, hi = 1e9, ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (check(mid))
            ans = mid, lo = mid + 1;
        else
            hi = mid - 1;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}