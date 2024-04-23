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
    int n, q; cin >> n >> q;
    
    for (int i = 1; i < n; i++)
        cout << i << " " << i + 1 << nl;

    int prev = n - 1;
    while (q--) {
        int x; cin >> x;
        if (x == prev)
            cout << "-1 -1 -1" << nl;
        else {
            cout << n << " " << prev << " " << x << nl;
            prev = x;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}