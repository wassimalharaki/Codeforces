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

    double ok = pow(nums[n - 1], 1.0 / (n - 1));
    int x = (int) ok;
    int a = x - 1, b = x, c = x + 1;
    auto get = [&](int k) -> int {
        if (k <= 0) return LONG_LONG_MAX;
        int curr = 1, cost = nums[0] - curr;
        for (int i = 1; i < n; i++) {
            int y = LONG_LONG_MAX / curr;
            if (k > y) {
                cost = LONG_LONG_MAX;
                break;
            }
            curr *= k;
            cost += abs(nums[i] - curr);
        }
        return cost;
    };
    cout << min({get(a), get(b), get(c)}) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}