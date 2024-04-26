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

    int m; cin >> m;

    v<int> b(m);
    for (int& x : b) cin >> x;

    if (accumulate(a.begin(), a.end(), 0ll) != accumulate(b.begin(), b.end(), 0ll)) {
        cout << -1;
        return;
    }

    int ans = 0;
    int i = 0, j = 0;
    int x = 0, y = 0;
    while (i < n and j < m)
        if (x > y)
            y += b[j++];
        else if (y > x)
            x += a[i++];
        else {
            ans++;
            y = b[j++];
            x = a[i++];
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