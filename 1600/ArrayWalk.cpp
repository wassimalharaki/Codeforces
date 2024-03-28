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
    int n, k, z; cin >> n >> k >> z;

    v<int> nums(n);
    for (int& a : nums) cin >> a;
    v<int> prefix(n + 1);
    partial_sum(all(nums), prefix.begin() + 1);

    int ans = nums[0], curr = nums[0];
    int need = max(2 * z - 1, 0ll);
    for (int i = 1; i <= k; i++) {
        curr += nums[i];
        int x = k - i;
        if (x < need) {
            int me = x / 2 * (nums[i - 1] + nums[i]) + (x & 1) * nums[i - 1];
            ans = max(ans, curr + me);
        }
        else if (need) {
            int y = x - need;
            int me = need / 2 * (nums[i - 1] + nums[i]) + nums[i - 1];
            me += prefix[i + y] - prefix[i];
            ans = max(ans, me + curr);
        }
    }
    cout << max(ans, curr) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}