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

    v<array<int, 2>> nums(n);
    for (auto& a : nums) cin >> a[1] >> a[0];
    sort(all(nums));

    int ans = 0, curr = 0, l = 0, r = n - 1;
    while (l <= r) {
        if (curr >= nums[l][0]) {
            curr += nums[l][1];
            ans += nums[l][1];
            l++;
        }
        else {
            int need = nums[l][0] - curr;
            int can = min(need, nums[r][1]);
            curr += can;
            nums[r][1] -= can;
            ans += 2 * can;
            if (nums[r][1] == 0)
                r--;
        }
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