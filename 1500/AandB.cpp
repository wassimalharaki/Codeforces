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
    int a, b; cin >> a >> b;
    int diff = abs(a - b);

    if (diff == 0) {
        cout << 0 << nl;
        return;
    }

    array<int, 2> parity{3, 1};
    int lo = 0, hi = 1e9, ans = INT_MAX;
    while (lo <= hi) {
        int x = (lo + hi) / 2;
        int mid = 4 * x + parity[diff & 1];

        if (mid * (mid + 1) / 2 >= diff)
            hi = x - 1, ans = mid;
        else if (++mid * (mid + 1) / 2 >= diff)
            hi = x - 1, ans = mid;
        else
            lo = x + 1;
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