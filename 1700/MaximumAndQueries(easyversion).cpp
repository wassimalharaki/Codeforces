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

const int N = 61;

void solve() {
    int n, q; cin >> n >> q;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<int> b(n);
    while (q--) {
        int k; cin >> k;

        for (int i = 0; i < n; i++)
            b[i] = a[i];
        
        int ans = 0;
        for (int i = N; i >= 0; i--) {
            int need = 0;
            for (int& x : b)
                if (!((1ll << i) & x)) {
                    int y = ((1ll << i) - 1) & x;
                    if (need < 1e18)
                        need += (1ll << i) - y;
                }

            if (need > k) continue;
            k -= need;
            ans += (1ll << i);
            for (int& x : b)
                if (!((1ll << i) & x)) {
                    int y = ((1ll << i) - 1) & x;
                    x += (1ll << i) - y;
                }
        }
        cout << ans << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}