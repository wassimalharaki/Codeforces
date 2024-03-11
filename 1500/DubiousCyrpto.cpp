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
    int l, r, m; cin >> l >> r >> m;

    int max = r - l, min = l - r;
    for (int i = l; i <= r; i++) {
        int n = m / i;
        if (n == 0) n++;
        int diff = m - i * n;
        if (diff >= min and diff <= max) {
            if (diff >= 0) {
                cout << i << " " << r << " " << r - diff << nl;
                return;
            }
            else {
                cout << i << " " << r + diff << " " << r << nl;
                return;
            }
        }
        n++;
        diff = m - i * n;
        if (diff >= min and diff <= max) {
            if (diff >= 0) {
                cout << i << " " << r << " " << r - diff << nl;
                return;
            }
            else {
                cout << i << " " << r + diff << " " << r << nl;
                return;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}