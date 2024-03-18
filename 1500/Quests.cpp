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
    int n, c, d; cin >> n >> c >> d;
    v<int> nums(n);
    for (int& a : nums) cin >> a;
    sort(nums.rbegin(), nums.rend());
    
    if (nums[0] * d < c) {
        cout << "Impossible" << nl;
        return;
    }

    int sum = accumulate(all(nums) - max(n - d, 0ll), 0ll);
    if (sum >= c) {
        cout << "Infinity" << nl;
        return;
    }

    int lo = 0, hi = d, ans = 0;
    while (lo <= hi) {
        int k = (lo + hi) / 2;

        int sum = 0, j = 0;
        for (int i = 1; i <= d; i++) {
            if (j < n)
                sum += nums[j++];
            if (i % (k + 1) == 0)
                j = 0;
        }

        if (sum >= c)
            lo = k + 1, ans = k;
        else
            hi = k - 1;
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