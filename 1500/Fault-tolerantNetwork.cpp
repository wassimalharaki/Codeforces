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

    v<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    int ans = 1e18;
    
    {
        int x = abs(a[0] - b[0]) + abs(a.back() - b.back());
        int y = abs(a[0] - b.back()) + abs(a.back() - b[0]);
        ans = min(x, y);
    }

    {
        int x = abs(a[0] - b[0]);
        int top = 1e18, bottom = 1e18;
        for (int i = 0; i < n; i++) {
            top = min(top, abs(a.back() - b[i]));
            bottom = min(bottom, abs(b.back() - a[i]));
        }
        ans = min(ans, x + top + bottom);

        x = abs(a[0] - b.back());
        top = bottom = 1e18;
        for (int i = 0; i < n; i++) {
            top = min(top, abs(a.back() - b[i]));
            bottom = min(bottom, abs(b[0] - a[i]));
        }
        ans = min(ans, x + top + bottom);

        x = abs(a.back() - b[0]);
        top = bottom = 1e18;
        for (int i = 0; i < n; i++) {
            top = min(top, abs(a[0] - b[i]));
            bottom = min(bottom, abs(b.back() - a[i]));
        }
        ans = min(ans, x + top + bottom);

        x = abs(a.back() - b.back());
        top = bottom = 1e18;
        for (int i = 0; i < n; i++) {
            top = min(top, abs(a[0] - b[i]));
            bottom = min(bottom, abs(b[0] - a[i]));
        }
        ans = min(ans, x + top + bottom);
    }

    {
        int tl, tr, bl, br;
        tl = tr = bl = br = 1e18;
        for (int i = 0; i < n; i++) {
            tl = min(tl, abs(a[0] - b[i]));
            tr = min(tr, abs(a.back() - b[i]));
            bl = min(bl, abs(b[0] - a[i]));
            br = min(br, abs(b.back() - a[i]));
        }
        ans = min(ans, tl + tr + bl + br);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}