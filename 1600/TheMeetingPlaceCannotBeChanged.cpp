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

    v<array<int, 2>> nums(n);
    for (auto& a : nums) cin >> a[0];
    for (auto& a : nums) cin >> a[1];
    sort(nums.begin(), nums.end());

    auto check = [&](double mid) {
        double r = nums[0][0] + mid * nums[0][1];
        for (int i = 1; i < n; i++) {
            double a = nums[i][0] - mid * nums[i][1];
            double b = nums[i][0] + mid * nums[i][1];
            if (a > r)
                return 0;
            else if (b < r)
                r = b;
        }
        return 1;
    };

    double lo = 0, hi = 1e9;
    for (int i = 0; i < 1e3; i++) {
        double mid = (lo + hi) / 2;

        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }
    cout << hi << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(12);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}