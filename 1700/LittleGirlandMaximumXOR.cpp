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
    int l, r; cin >> l >> r;

    int ans = 0;
    for (int i = 62; i >= 0; i--) {
        bool a = (1ll << i) & r;
        bool b = (1ll << i) & l;
        if (ans) ans += (1ll << i);
        else if (a ^ b) ans += (1ll << i);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}