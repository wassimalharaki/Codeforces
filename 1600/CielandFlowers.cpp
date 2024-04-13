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

int check(int x, array<int, 3> cnt) {
    cnt[0] -= x; cnt[1] -= x; cnt[2] -= x;
    return x + cnt[0] / 3 + cnt[1] / 3 + cnt[2] / 3;
}

void solve() {
    array<int, 3> cnt;
    cin >> cnt[0] >> cnt[1] >> cnt[2];
    int ans = check(0, cnt);
    for (int i = 1; i <= min(3ll, *min_element(all(cnt))); i++)
        ans = max(ans, check(i, cnt));
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}