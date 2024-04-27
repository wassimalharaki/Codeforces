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
    int n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    int x = n / a, y = n / b, z = n / lcm(a, b);
    cout << (x - z) * p + (y - z) * q + max(p, q) * z;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}