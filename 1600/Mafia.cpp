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

    int lo = *max_element(all(nums)), hi = 1e18, ans = 1e18;
    while (lo <= hi) {
        int mid = (hi - lo) / 2 + lo;

        int x = 0;
        for (int i = 0; i < n; i++) {
            x += mid - nums[i];
            if (x >= mid) break;
        }
        
        if (x >= mid)
            ans = mid, hi = mid - 1;
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