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
    int n, k; cin >> n >> k;

    v<int> nums(n);
    for (int& a : nums) cin >> a;
    sort(all(nums));

    if (n == 1) {
        cout << max(0ll, nums[0] - k) << nl;
        return;
    }

    int me = nums[0], sum = me;
    int x = accumulate(all(nums), 0ll), y = 1;
    int ans = max(x - k, 0ll);
    for (int i = n - 1; i > 0; i--) {
        sum += nums[i];
        int ops = max(me + (x - k - sum) / ++y, 0ll);
        if (x - sum + (me - ops) * y > k)
            ops++;
        ans = min(ans, ops + y - 1);
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