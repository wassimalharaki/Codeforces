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
    int a, b, q; cin >> a >> b >> q;
    if (a > b) swap(a, b);
    int x = lcm(a, b);

    auto f = [&](int l, int r) -> int {
        int ans = r - l + 1;
        int first_multiple = (l + x - 1) / x;
        int last_multiple = r / x;
        if (last_multiple * x + b - 1 <= r)
            last_multiple++;
        else
            ans -= b - (last_multiple * x + b - 1 - r);
        ans -= (last_multiple - first_multiple) * b;
        first_multiple--;
        if (first_multiple * x + b - 1 >= l)
            ans -= first_multiple * x + b - l; 
        return ans;
    };

    while (q--) {
        int l, r; cin >> l >> r;
        cout << f(l, r) << " ";
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}