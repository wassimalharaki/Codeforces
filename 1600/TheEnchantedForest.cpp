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

void solve() {
    int n, k; cin >> n >> k;

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    if (k <= n) {
        int ans = 0;
        for (int i = 0; i < k; i++)
            ans += nums[i];
        int curr = ans;

        for (int i = k; i < n; i++) {
            curr -= nums[i - k];
            curr += nums[i];
            ans = max(ans, curr);
        }
        cout << ans + (k - 1) * k / 2 << nl;
    }
    else {
        int ans = accumulate(nums.begin(), nums.end(), 0ll);
        ans += (2 * k - (n + 1)) * n / 2;
        cout << ans << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}