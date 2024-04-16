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

const int N = 4e5 + 10;
int have[N];

void solve() {
    int q, x; cin >> q >> x;
    
    memset(have, 0, sizeof(have));
    int ans = 0;
    while (q--) {
        int a; cin >> a;
        have[a % x]++;
        while (have[ans % x])
            have[ans++ % x]--;
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