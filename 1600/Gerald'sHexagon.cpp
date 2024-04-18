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
    v<int> cnt(6);
    for (int& a : cnt) cin >> a;

    int ans = 0, x = 2 * cnt[0] - 1;
    for (int i = 1; i <= cnt[1] + cnt[2]; i++) {
        if (i <= cnt[1])
            x++;
        else if (i > cnt[1] + 1)
            x--;
        if (i <= cnt[5])
            x++;
        else if (i > cnt[5] + 1)
            x--;
        ans += x;
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