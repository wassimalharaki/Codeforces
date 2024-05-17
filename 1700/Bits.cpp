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
    
    int i = 0, ans = 0;
    for (i = 60; i >= 0; i--)
        if (((1ll << i) & l) == ((1ll << i) & r))
            ans += ((1ll << i) & l);
        else
            break;

    if (i == -1) {
        cout << ans << nl;
        return;
    }

    bool ok = 1;
    for (int j = i; j >= 0; j--)
        if (((1ll << j) & r) == 0)
            ok = 0;
    
    if (ok)
        cout << r << nl;
    else {
        while (--i >= 0)
            ans += (1ll << i);
        cout << ans << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}