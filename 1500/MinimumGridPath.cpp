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

    int x = nums[0], y = nums[1];
    array<int, 2> min{x, y};
    int ans = n * (x + y);
    for (int i = 2; i < n; i++) {
        int z = n - (i + 1) / 2;
        if (i & 1) {
            y += nums[i];
            min[1] = std::min(min[1], nums[i]);
            int curr = x + y + z * (min[0] + min[1]);
            ans = std::min(ans, curr);
        }
        else {
            x += nums[i];
            min[0] = std::min(min[0], nums[i]);
            int curr = x + y + min[1] * z + min[0] * (z - 1);
            ans = std::min(ans, curr);
        }
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