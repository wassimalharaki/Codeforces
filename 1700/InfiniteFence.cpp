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
    int r, b, k; cin >> r >> b >> k;
    if (b > r) swap(r, b);
    int x = (r - 1 - gcd(r, b)) / b + 1;
    cout << (x < k ? "OBEY" : "REBEL") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}