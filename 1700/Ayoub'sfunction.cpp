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

int get(int x) {
    return x * (x + 1) / 2;
}

int half(int x) {
    return get((x + 1) / 2 - 1) + get(x - (x + 1) / 2);
}

void solve() {
    int n, m; cin >> n >> m;

    if (m == 0) {
        cout << 0 << nl;
        return;
    }

    int lo = 0, hi = 1e9, d = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (n - (mid + 1) * m < mid)
            d = mid - 1, hi = mid - 1;
        else
            lo = mid + 1;
    }
    int x = n - (d + 1) * m - d;
    cout << get(n) - (m - x + 1) * get(d) - x * get(d + 1) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}