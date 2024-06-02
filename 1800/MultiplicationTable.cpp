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
    int n, m, k; cin >> n >> m >> k;

    auto get = [&](int x) -> array<int, 2> {
        int l = 0, r = 0;
        for (int i = 1; i <= n; i++) {
            l += min(m, (x + i - 1) / i - 1);
            r += min(m, x / i);
        }
        return {l + 1, r};
    };

    int lo = 1, hi = n * m;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        auto x = get(mid);

        if (k >= x[0] and k <= x[1]) {
            cout << mid;
            break;
        }
        else if (k >= x[0])
            lo = mid + 1;
        else
            hi = mid - 1;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}