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
    array<int, 3> a;
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());

    int ans = 0;
    int x = a[1] - a[0];
    int y = a[2] - a[0];

    if (y >= 2 * x) {
        a[2] -= 2 * x;
        a[1] -= x;
        ans += x;

        int z = min((a[2] - a[0]) * 2 / 3, 2 * a[0]);
        a[2] -= 2 * z;
        a[1] -= z / 2;
        a[0] -= (z + 1) / 2;
        ans += z + a[0];
    }
    else {
        int z = a[2] - a[1];
        a[2] -= 2 * z;
        a[1] -= z;
        y -= 2 * z;
        x -= z;
        ans += z;

        int k = x / 3;
        ans += 2 * k;
        a[2] -= 3 * k;
        a[1] -= 3 * k;
        y -= 3 * k;
        x -= 3 * k;

        ans += a[0] + (x == 2);
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}