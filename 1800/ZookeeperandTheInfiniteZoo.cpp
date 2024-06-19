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
    uint32_t a, b; cin >> a >> b;

    if (a > b or popcount(b) > popcount(a)) {
        cout << "NO" << nl;
        return;
    }

    int x = 0;
    for (int i = 1; i < (1 << 30); i <<= 1) {
        if (i & a) x++;
        if (i & b) x--;
        if (x < 0) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}