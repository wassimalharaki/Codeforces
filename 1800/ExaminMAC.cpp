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
    int n, c; cin >> n >> c;
    
    c += 2;
    int ans = (c - 1) * c / 2;
    array<int, 2> parity{0, 0};
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        ans -= c - a + a / 2 - ++parity[a & 1];
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}