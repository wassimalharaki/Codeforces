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

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    auto check = [&](int k) -> bool {
        v<int> ok(nums);

        for (int i = n - 1; i >= 2; i--) {
            int d = min((ok[i] - k) / 3, nums[i] / 3);
            d = max(d, 0ll);
            ok[i] -= 3 * d;
            ok[i - 1] += d;
            ok[i - 2] += 2 * d;
        }
    
        return *min_element(all(ok)) >= k;
    };

    int lo = 0, hi = 1e9, ans = 0;
    while (lo <= hi) {
        int mid = lo + hi >> 1;

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