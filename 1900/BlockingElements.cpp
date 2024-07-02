#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& a : a) cin >> a;

    auto ok = [&](int k) -> bool {
        v<int> dp(n + 1);
        multiset<int> have{0, a[0]};
        dp[0] = 0; dp[1] = a[0];
        int l = 0, sum = a[0];
        for (int i = 1; i < n; i++) {
            while (sum > k) {
                have.erase(have.find(dp[l]));
                sum -= a[l++];
            }
            dp[i + 1] = a[i] + *have.begin();
            have.insert(dp[i + 1]);
            sum += a[i];
        }

        int min = dp.back(); sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (sum + a[i] > k) break;
            sum += a[i];
            min = std::min(min, dp[i]);
        }
        return min <= k;
    };

    int lo = *max_element(all(a)), hi = 1e14, ans = 1e18;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (ok(mid))
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
    cin >> T;
    while (T--) solve();
}