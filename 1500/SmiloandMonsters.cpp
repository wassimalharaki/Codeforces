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
    sort(all(nums));

    int ans = 0, x = 0;
    int l = 0, r = n - 1;
    while (l <= r)
        if (l == r) {
            int k = (nums[l] - x) / 2;
            ans += k + (x + k > 0);
            nums[l] -= k;
            nums[l] -= x + k;
            ans += nums[l] > 0;
            l++;
        }
        else if (x + nums[l] >= nums[r]) {
            nums[l] -= nums[r] - x;
            ans += nums[r] - x + 1;
            x = 0;
            r--;
        }
        else {
            x += nums[l];
            ans += nums[l];
            l++;
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