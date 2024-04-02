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
    int n, m; cin >> n >> m;

    v<int> a(n), b(m);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    for (int x = 0; x <= (1 << 9); x++) {
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            bool ok2 = 0;
            for (int j = 0; j < m; j++) {
                int y = a[i] & b[j];
                if ((y | x) == x)
                    ok2 = 1;
            }
            if (not ok2) ok = 0;
        }
        if (ok) {
            cout << x;
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}