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
    int n, x; cin >> n >> x;

    bool ok = 0;
    bool all = 1;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a == x) ok = 1;
        else all = 0;
        a <= x ? l += x - a : r += a - x;
    }
    cout << (all ? 0 : ok ? 1 : 1 + (l != r)) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}