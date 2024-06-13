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

    v<int> a(n);
    for (int& x : a) cin >> x;

    if (a[0] != 1) {
        cout << 1 << nl;
        return;
    }

    auto get = [&](int x) -> int {
        int y = 0;
        while (x > 1) {
            auto it = upper_bound(a.begin(), a.end(), x);

            int z = *prev(it);
            int i = it - a.begin();
            if (z == x)
                y++, x -= i;
            else {
                y += (x - z + i - 1) / i;
                x -= (x - z + i - 1) / i * i;
            }
        }
        return y - (x == 0);
    };

    int lo = 1, hi = 4e10 + 1, ans;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (get(mid) >= k)
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
    cin >> T;
    while (T--) solve();
}