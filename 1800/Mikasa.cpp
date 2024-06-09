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
    int n, m; cin >> n >> m;
    int x = ((1 << 31) - 1) ^ n;

    auto exists = [&](int y) -> bool {
        return (n ^ y) <= m;
    };

    bool ok = 1;
    while (ok) {
        ok = 0;
        for (int i = 30; i >= 0 and not ok; i--)
            if ((1 << i) & x)
                if (not exists(x ^ (1 << i)))
                    x ^= 1 << i, ok = 1;
    }
    cout << x << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}