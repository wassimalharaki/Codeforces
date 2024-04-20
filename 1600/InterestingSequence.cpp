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
    int n, x; cin >> n >> x;

    if ((n & x) != x)
        cout << -1 << nl;
    else if (n == x)
        cout << n << nl;
    else {
        int msb = 63 - __builtin_clzll(n ^ x);
        if (x & ((1ll << msb) - 1))
            cout << -1 << nl;
        else {
            int ans = n + (1ll << msb);
            if (n & (1ll << (msb + 1)))
                cout << -1 << nl;
            else {
                int y = n + (1ll << msb);
                y &= (1ll << 62) - (1ll << msb);
                cout << y << nl;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}