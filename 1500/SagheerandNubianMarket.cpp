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
    int n, s; cin >> n >> s;

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    int lo = 0, hi = n, ans = 0, cost = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        v<int> weighted(n);
        for (int i = 0; i < n; i++)
            weighted[i] = nums[i] + (i + 1) * mid;
        sort(all(weighted));

        int sum = 0;
        for (int i = 0; i < mid; i++)
            sum += weighted[i];
        
        if (sum <= s)
            lo = mid + 1, ans = mid, cost = sum;
        else
            hi = mid - 1;
    }
    cout << ans << " " << cost << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}