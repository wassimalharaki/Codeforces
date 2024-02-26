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
    int lo = 0, hi = 1e18, ans = INT_MAX;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        int sum = 0, curr = 1;
        while (mid / curr) {
            sum += mid / curr;
            curr *= k;
            if (sum >= n) break;
        }

        if (sum >= n)
            hi = mid - 1, ans = mid;
        else
            lo = mid + 1;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}