#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) {
        cin >> x;
        x = abs(x);
    }

    bitset<(int) 2e6 + 1> bs;
    for (int i = 0; i < n; i++) {
        bs.reset();
        bs[1e6] = 1;
        for (int j = 0; j < n; j++)
            if (i != j)
                bs |= (bs << a[j]) | (bs >> a[j]);
        if (bs[a[i] + 1e6]) {
            cout << "YES" << nl;
            return;
        }
    }
    cout << "NO" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}