#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> a(n + 1), b(n);
    v<int> c(n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (i) b[i] = b[i - 1];
        if (x > n) continue;
        a[x].push_back(i);
        if (++c[x] == x)
            b[i].push_back(x);
    }

    while (m--) {
        int l, r; cin >> l >> r;
        l--, r--;

        int ans = 0;
        for (int& x : b[r]) {
            auto it1 = lower_bound(a[x].begin(), a[x].end(), l);
            auto it2 = --upper_bound(a[x].begin(), a[x].end(), r);
            if (it1 == a[x].end()) continue;
            int y = it2 - it1 + 1;
            ans += (y == x);
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