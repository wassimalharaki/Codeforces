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

    int lo = 0, hi = 1e9, m, k;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        int l = 0, r = 1e9;
        bool ok = 1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == -1) {
                if (nums[i + 1] == -1)
                    continue;
                else {
                    int min = nums[i + 1] - mid;
                    int max = nums[i + 1] + mid;
                    l = std::max(l, min);
                    r = std::min(r, max);
                }
            }
            else {
                if (nums[i + 1] == -1) {
                    int min = nums[i] - mid;
                    int max = nums[i] + mid;
                    l = std::max(l, min);
                    r = std::min(r, max);
                }
                else {
                    if (abs(nums[i + 1] - nums[i]) > mid)
                        ok = 0;
                }
            }
        }

        if (ok and l <= r)
            hi = mid - 1, m = mid, k = l;
        else
            lo = mid + 1;
    }
    cout << m << " " << k << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}