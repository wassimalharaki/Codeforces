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
    int n, k; cin >> n >> k;

    map<int, int> have; have[0] = 1;
    int ans = 0, curr = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        curr += x;
        int y = 1;
        while (y <= 1e14) {
            if (have.count(curr - y))
                ans += have[curr - y];
            y *= k;
            if (k == 1) break;
            if (k == -1 and y == 1) break;
        }
        ++have[curr];
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