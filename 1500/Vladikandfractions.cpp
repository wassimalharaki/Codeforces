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
    int n; cin >> n;

    if (n == 1) {
        cout << -1;
        return;
    }

    for (int x = n / 2 + 1; x <= 1e6; x++) {
        for (int y = n * x / (2 * x - n) + 1; y <= 1e6; y++) {
            int num = n * x * y;
            int deno = 2 * x * y - n * y - n * x;
            if (deno == 0) continue;
            if (num % deno) continue;
            int z = num / deno;
            if (z >= 1 and z <= 1e9) {
                cout << x << " " << y << " " << z << nl;
                return;
            }
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