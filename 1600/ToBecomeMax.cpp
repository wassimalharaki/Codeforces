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

    int lo = 0, hi = 1e9, ans;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        int x = INT_MAX;
        for (int i = 0; i < n; i++) {
            int curr = mid, need = 0;
            bool ok = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] >= curr) {
                    ok = 1;
                    break;
                }
                need += curr-- - nums[j];
            }
            if (ok) x = min(x, need);
        }

        if (x <= k)
            lo = mid + 1, ans = mid;
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