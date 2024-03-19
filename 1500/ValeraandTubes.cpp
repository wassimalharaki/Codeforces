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
    int n, m, k; cin >> n >> m >> k;
    bool ok = 1;
    int r = 1, c = 1;
    auto upd = [&]() {
        if (ok) {
            if (c + 1 <= m)
                c++;
            else {
                r++;
                ok = 0;
            }
        }
        else {
            if (c - 1 >= 1)
                c--;
            else {
                r++;
                ok = 1;
            }
        }
    };

    for (int i = 0; i < k - 1; i++) {
        cout << 2 << " " << r << " " << c << " ";
        upd();
        cout << r << " " << c << nl;
        upd();
    }

    int x = n * m - 2 * (k - 1);
    cout << x << " ";
    for (int i = 0; i < x; i++) {
        cout << r << " " << c << " ";
        upd();
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}