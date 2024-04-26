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
    int n; cin >> n;

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    int ans = 0, curr = 0;
    int min_even = 0, max_odd = 0;
    for (int i = 0; i < n - 1; i++) {
        curr += abs(nums[i] - nums[i + 1]) * (i & 1 ? -1 : 1);
        ans = max(ans, curr - min_even);
        ans = max(ans, max_odd - curr);
        if (i & 1)
            min_even = min(min_even, curr);
        else
            max_odd = max(max_odd, curr);
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