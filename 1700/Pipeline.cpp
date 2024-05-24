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

    if (n == 1)
        cout << 0;
    else if (n > (1 + k) * (k - 2) / 2 + 2)
        cout << -1;
    else {
        int lo = 1, hi = k - 1, ans;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            int x = (2 * k - mid + 1) * mid / 2 - mid + 1;
            if (x >= n)
                ans = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
        cout << ans;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}