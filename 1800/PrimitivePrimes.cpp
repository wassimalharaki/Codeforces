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
    int n, m, p; cin >> n >> m >> p;

    v<int> a(n), b(m);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    if (m > n) {
        swap(n, m);
        swap(a, b);
    }

    int x = 0, y = 0;
    for (int i = n - 1; i >= 0; i--)
        if (a[i] % p) {
            x = i;
            break;
        }
    for (int i = m - 1; i >= 0; i--)
        if (b[i] % p) {
            y = i;
            break;
        }
    cout << x + y << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}