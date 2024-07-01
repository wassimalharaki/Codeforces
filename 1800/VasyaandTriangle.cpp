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
    int n, m, k; cin >> n >> m >> k;

    if (n * m * 2 % k)
        cout << "NO" << nl;
    else if (m * 2 % k == 0) {
        cout << "YES" << nl;
        cout << "0 0" << nl;
        cout << n << " 0" << nl;
        cout << "0 " << m * 2 / k << nl;
    }
    else if (n * 2 % k == 0) {
        cout << "YES" << nl;
        cout << "0 0" << nl;
        cout << n * 2 / k << " 0" << nl;
        cout << "0 " << m << nl;
    }
    else if (m > n) {
        int x = k / gcd(m * 2, k);
        cout << "YES" << nl;
        cout << "0 0" << nl;
        cout << n / x << " 0" << nl;
        cout << "0 " << x * m * 2 / k << nl;
    }
    else {
        int x = k / gcd(n * 2, k);
        cout << "YES" << nl;
        cout << "0 0" << nl;
        cout << x * n * 2 / k << " 0" << nl;
        cout << "0 " << m / x << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}