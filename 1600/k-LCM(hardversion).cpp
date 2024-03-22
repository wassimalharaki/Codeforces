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
    int n, k; cin >> n >> k;

    while (k != 3) {
        cout << 1 << " ";
        n--; k--;
    }

    if (n & 1)
        cout << n / 2 << " " << n / 2 << " " << 1 << nl;
    else if (n / 2 & 1)
        cout << n / 2 - 1 << " " << n / 2 - 1 << " " << 2 << nl;
    else
        cout << n / 2 << " " << n / 4 << " " << n / 4 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}