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
    int n, m, k; cin >> n >> m >> k;

    v<int> a(n), b(m), c(k);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    for (int& x : c) cin >> x;
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    int l, r;
    int curr = 0;
    for (int i = 0; i < n - 1; i++) {
        int x = a[i + 1] - a[i];
        if (x > curr) {
            l = a[i], r = a[i + 1];
            curr = x;
        }
    }
    int target = (l + r) / 2;

    int best = l;
    for (int i = 0; i < m; i++) {
        auto it = lower_bound(c.begin(), c.end(), max(target - b[i], 0ll));
        if (it == c.end()) it--;

        int me = b[i] + *it;
        int diff = max(me - l, r - me);
        if (diff < curr) {
            curr = diff;
            best = me;
        }
        if (it == c.begin()) continue;

        it--;
        me = b[i] + *it;
        diff = max(me - l, r - me);
        if (diff < curr) {
            curr = diff;
            best = me;
        }
    }

    a.push_back(best);
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, a[i + 1] - a[i]);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}