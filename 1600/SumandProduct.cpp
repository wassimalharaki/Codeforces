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

int bsqrt(int n) {
    int lo = 0, hi = 2e9;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (mid * mid == n)
            return mid;
        else if (mid * mid > n)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return -1;
}

void solve() {
    int n; cin >> n;

    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        ++cnt[a];
    }

    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y;

        int d = x * x - 4 * y, k = bsqrt(d);
        if (k == -1)
            cout << 0 << " ";
        else if ((x ^ k) & 1)
            cout << 0 << " ";
        else if (d == 0)
            cout << cnt[x / 2] * (cnt[x / 2] - 1) / 2 << " ";
        else
            cout << cnt[(x + k) / 2] * cnt[(x - k) / 2] << " ";
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}