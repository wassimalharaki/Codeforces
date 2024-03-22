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

    int even = 0, odd = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        a = abs(a);
        a & 1 ? odd++ : even++;
    }

    if (n & 1) {
        if (odd & 1) {
            cout << ((odd / 2 + 1) & 1 ? "Bob" : "Alice") << nl;
        }
        else {
            cout << ((odd / 2) & 1 ? "Bob" : "Alice") << nl;
        }
    }
    else {
        if (odd & 1) {
            cout << "Alice" << nl;
        }
        else {
            cout << ((odd / 2) & 1 ? "Bob" : "Alice") << nl;
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