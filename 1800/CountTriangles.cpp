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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    v<int> cnt(d), pref(d);
    for (int i = 0; i < d; i++) {
        int z = c, y = c - i;
        int add = max(0ll, b - y);
        y += add; z += add;
        cnt[i] += max(0ll, min(c - y + 1, d - z + 1));
    }
    partial_sum(cnt.begin(), cnt.end(), pref.begin());

    int ans = 0;
    for (int x = a; x <= b; x++)
        ans += pref[x - 1];
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}