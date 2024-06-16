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
    int n; cin >> n;

    array<int, 3> a, b;
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    int x = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
    int y = max(0ll, a[0] - b[0] - b[2]) + max(0ll, a[1] - b[0] - b[1])
        + max(0ll, a[2] - b[1] - b[2]);
    cout << y << " " << x;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}