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

    map<int, int> ok;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        for (int i = 0; i < 32; i++)
            if (ok.count((1ll << i) - a))
                ans += ok[(1ll << i) - a];
        ok[a]++;
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