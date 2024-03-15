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
    int n, x, p; cin >> n >> x >> p;

    for (int i = 1; i <= 2 * n and i <= p; i++)
        if ((i * (i + 1) / 2 + x) % n == 0) {
            cout << "YES" << nl;
            return;
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