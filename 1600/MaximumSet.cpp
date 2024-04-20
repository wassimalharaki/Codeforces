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
    int n = 0;
    while ((l << n) <= r) n++;

    cout << n << " ";
    if (n == 1)
        cout << r - l + 1 << nl;
    else if (n == 2)
        cout << r / 2 - l + 1 + max(0ll, r / 3 - l + 1) << nl;
    else {
        int ans = r / (1 << --n) - l + 1;
        if (l * (1 << (n - 1)) * 3 <= r)
            ans += (r / ((1 << (n - 1)) * 3) - l + 1) * n;
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