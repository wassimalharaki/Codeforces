#include <bits/stdc++.h>
using namespace std;
// #define int long long
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

    v<array<array<int, 2>, 31>> left(n), right(n);

    for (int i = 1; i < n; i++) {
        left[i] = left[i - 1];
        for (int x = 0; x < 31; x++) {
            left[i][x][0]++;
            if (nums[i - 1] & (1 << x))
                swap(left[i][x][0], left[i][x][1]);
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        right[i] = right[i + 1];
        for (int x = 0; x < 31; x++) {
            right[i][x][0]++;
            if (nums[i + 1] & (1 << x))
                swap(right[i][x][0], right[i][x][1]);
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int msb = 31 - __builtin_clz(nums[i]);
        ans += left[i][msb][1] + right[i][msb][1]
            + 1ll * left[i][msb][1] * right[i][msb][0]
            + 1ll * left[i][msb][0] * right[i][msb][1];
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