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
    int n, a, b; cin >> n >> a >> b;

    if (a == 1) {
        cout << ((n - 1) % b == 0 ? "YES" : "NO") << nl;
        return;
    }

    int x = 1;
    while (x <= n) {
        if ((n - x) % b == 0) {
            cout << "YES" << nl;
            return;
        }
        int y = LONG_LONG_MAX / x;
        if (y < a) break;
        x *= a;
    }
    cout << "NO" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}