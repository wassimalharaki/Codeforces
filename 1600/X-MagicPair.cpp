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
    int a, b, x; cin >> a >> b >> x;
    if (b > a) swap(a, b);
    b = min(a - b, b);

    while (a > x) {
        b = min(a - b, b);
        if (b == 0) break;
        if (a % b == x % b or a % (a - b) == x % (a - b)) {
            a = x;
            break;
        }
        a -= (a - b + 1) / b * b;
    }
    cout << (a == x ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}