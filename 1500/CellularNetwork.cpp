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

    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(all(b), a[i]);
        if (it == b.begin())
            ans = max(ans, *it - a[i]);
        else if (it == b.end())
            ans = max(ans, a[i] - *(--it));
        else
            ans = max(ans, min(a[i] - *(--it), *it - a[i]));
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