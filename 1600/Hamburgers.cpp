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
    string s; cin >> s;
    array<int, 3> need, have, cost;
    need[0] = count(all(s), 'B');
    need[1] = count(all(s), 'S');
    need[2] = count(all(s), 'C');
    cin >> have[0] >> have[1] >> have[2];
    cin >> cost[0] >> cost[1] >> cost[2];
    int x; cin >> x;

    int lo = 0, hi = 1e14, ans;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        int b = need[0] * mid;
        int s = need[1] * mid;
        int c = need[2] * mid;
        b = max(0ll, b - have[0]);
        s = max(0ll, s - have[1]);
        c = max(0ll, c - have[2]);
        int y = b * cost[0] + s * cost[1] + c * cost[2];

        if (y <= x)
            lo = mid + 1, ans = mid;
        else
            hi = mid - 1;
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}