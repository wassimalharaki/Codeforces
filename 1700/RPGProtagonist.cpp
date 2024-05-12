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
    int p, f; cin >> p >> f;
    array<int, 2> cnt; cin >> cnt[0] >> cnt[1];
    array<int, 2> w; cin >> w[0] >> w[1];

    if (w[0] > w[1])
        swap(w[0], w[1]),
        swap(cnt[0], cnt[1]);

    int ans = 0;
    for (int i = 0; i <= cnt[0]; i++) {
        if (i * w[0] > p) break;

        array<int, 2> rem(cnt);

        int me = i;
        int left = p - i * w[0];
        rem[0] -= i;

        int sub = min(left / w[1], rem[1]);
        me += sub;
        rem[1] -= sub;

        sub = min(f / w[0], rem[0]);
        int him = sub;
        rem[0] -= sub;
        left = f - sub * w[0];

        sub = min(left / w[1], rem[1]);
        him += sub;
        rem[1] -= sub;
        ans = max(ans, me + him);
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