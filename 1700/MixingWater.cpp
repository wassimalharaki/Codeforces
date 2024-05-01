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
    int h, c, t; cin >> h >> c >> t;

    auto get = [&](int k) {
        return (k * (h + c) + h) / (2 * k + 1);
    };

    if (t >= h)
        cout << 1 << nl;
    else if (t <= (c + h) / 2)
        cout << 2 << nl;
    else {
        int lo = 0, hi = 1e9, up = 1e9, down = 1e9;
        while (lo <= hi) {
            int k = (lo + hi) / 2;

            if (get(k) >= t)
                up = k, lo = k + 1;
            else
                down = k, hi = k - 1;
        }

        int x= up, y = down;
        int a = (2 * y + 1) * (x * (c + h) + h - (2 * x + 1) * t);
        int b = (2 * x + 1) * ((2 * y + 1) * t - y * (c + h) - h);

        if (a <= b)
            cout << 2 * up + 1 << nl;
        else
            cout << 2 * down + 1 << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}