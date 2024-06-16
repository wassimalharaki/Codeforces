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
    int n, m; cin >> m >> n;

    v a(m, v<int>(n));
    for (auto& x : a)
        for (auto& y : x)
            cin >> y;

    auto check = [&](int k) -> bool {
        v<int> good(n);
        bool ok = 0;

        for (int i = 0; i < m; i++) {
            int x = 0;
            for (int j = 0; j < n; j++)
                good[j] |= a[i][j] >= k, x += a[i][j] >= k;
            ok |= x > 1;
        }
        return ok and *min_element(good.begin(), good.end());
    };

    int lo = 1, hi = 1e9, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (check(mid))
            lo = mid + 1, ans = mid;
        else
            hi = mid - 1;
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