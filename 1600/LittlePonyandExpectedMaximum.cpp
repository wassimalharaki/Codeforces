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

// O(log(b))
double binpow(double a, int b) {
    double res = 1;
    while (b) {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve() {
    int m, n; cin >> m >> n;
    double ans = m;
    for (int i = 1; i < m; i++)
        ans -= binpow(1.0 * i / m, n);
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(12);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}