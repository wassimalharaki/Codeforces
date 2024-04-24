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
    int n, k; cin >> n >> k;

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    int lo = 0, hi = n, ans, l, r;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        bool ok = 0;
        int ones = 0, zeroes = 0;
        for (int i = 0; i < mid; i++)
            nums[i] ? ones++ : zeroes++;

        if (zeroes <= k) {
            l = 0, r = mid - 1;
            ok = 1;
        }
        
        for (int i = mid; i < n; i++) {
            nums[i - mid] ? ones-- : zeroes--;
            nums[i] ? ones++ : zeroes++;
            if (zeroes <= k) {
                l = i - mid + 1, r = i;
                ok = 1;
            }
        }

        if (ok)
            lo = mid + 1, ans = mid;
        else
            hi = mid - 1;
    }
    cout << ans << nl;
    for (int i = l; i <= r; i++)
        nums[i] = 1;
    for (int& a : nums)
        cout << a << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}