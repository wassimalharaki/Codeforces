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
    if (n == 1) {
        cout << 1;
        return;
    }
    if (n == 2) {
        cout << 2;
        return;
    }

    int a = 1, b = 2, c = 3;
    int ans = lcm(a, lcm(b, c));
    while (a++, b++, ++c <= n)
        ans = max(ans, lcm(a, lcm(b, c)));
    for (int c = 1; c <= n; c++)
        ans = max(ans, lcm(n, lcm(n - 1, c)));
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}