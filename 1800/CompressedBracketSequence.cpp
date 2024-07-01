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
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    int ans = 0;
    for (int i = 1; i < n; i += 2) {
        int y = 0, x = a[i];
        for (int j = i - 1; j >= 0 and x >= 0; j--) {
            if (j & 1 ^ 1) {
                if (a[j] - y >= 0)
                    ans += (j != i - 1) + min(a[j] - y, x);
                y -= a[j];
                if (y < 0)
                    x += y, y = 0;
            }
            else
                y += a[j];
        }
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}