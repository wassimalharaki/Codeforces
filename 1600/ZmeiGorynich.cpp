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
    int n, h; cin >> n >> h;

    int x = 0, y = -INT_MAX;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        x = max(x, a);
        y = max(y, a - b);
    }

    if (h - x <= 0)
        cout << 1 << nl;
    else if (y <= 0)
        cout << -1 << nl;
    else
        cout << 1 + (h - x + y - 1) / y << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}