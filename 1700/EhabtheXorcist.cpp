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
    int x, y; cin >> x >> y;

    if (x > y)
        cout << -1 << nl;
    else if ((x ^ y) & 1)
        cout << -1 << nl;
    else if (x == 0) {
        if (y == 0)
            cout << 0 << nl;
        else
            cout << 2 << nl << y / 2 << " " << y / 2 << nl;
    }
    else if (x == y)
        cout << 1 << nl << x << nl;
    else if (x & 1) {
        int a = y / 2;
        if (((a + x / 2) ^ (a - x / 2 + 1)) == x)
            cout << 2 << nl << a + x / 2 << " " << a - x / 2 + 1 << nl;
        else
            cout << 3 << nl << x << " " << (y - x) / 2 << " " << (y - x) / 2 << nl;
    }
    else {
        int a = y / 2;
        if (((a - x / 2) ^ (a + x / 2)) == x)
            cout << 2 << nl << a - x / 2 << " " << a + x / 2 << nl;
        else
            cout << 3 << nl << x << " " << a - x / 2 << " " << a - x / 2 << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}