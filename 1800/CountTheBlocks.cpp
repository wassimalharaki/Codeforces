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

const int mod = 998244353;

void solve() {
    int n; cin >> n;
    if (n == 1)
        cout << 10 << nl;
    else {
        v<int> ans(n);
        ans[n - 1] = 10;
        ans[n - 2] = 180;
        int x = 100, y = 10;
        for (int k = n - 3, i = 1, j = 3; k >= 0; k--, i++, j++) {
            ans[k] = (9 * j * x % mod - 9 * i * y % mod);
            ans[k] = (ans[k] % mod + mod) % mod;
            x = x * 10 % mod;
            y = y * 10 % mod;
        }
        for (int& x : ans)
            cout << x << " ";
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}