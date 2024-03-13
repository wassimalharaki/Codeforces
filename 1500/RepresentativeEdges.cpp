#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

const double eps = 1e-6;

bool eq(double a, double b) {
    return abs(a - b) <= eps;
}

void solve() {
    int n; cin >> n;

    v<double> nums(n);
    for (double& a : nums) cin >> a;

    if (n == 1) {
        cout << 0 << nl;
        return;
    }

    auto get = [&](double diff, int x) -> int {
        v<double> a = nums;
        int ans = 0;
        for (int i = x - 1; i >= 0; i--)
            if (not eq(a[i], a[i + 1] - diff))
                ans++, a[i] = a[i + 1] - diff;
        
        for (int i = x; i < n - 1; i++)
            if (not eq(a[i + 1], a[i] + diff))
                ans++, a[i + 1] = a[i] + diff;

        return ans;
    };

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            ans = min(ans, get((nums[j] - nums[i]) / (j - i), i));
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}