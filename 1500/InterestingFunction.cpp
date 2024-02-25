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
    int l, r; cin >> l >> r;

    auto ok = [](int n) -> int {
        int ans = 0, i = 1;
        while (1) {
            int x = n / i;
            if (x == 0) break;
            ans += x;
            i *= 10;
        }
        return ans;
    };
    cout << ok(r) - ok(l) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}