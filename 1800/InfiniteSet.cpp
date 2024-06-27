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

const int mod = 1e9 + 7;

void add(int& a, int b) {
    a = (a + b) % mod;
}

void solve() {
    int n, p; cin >> n >> p;

    v<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());

    v<int> dp(p);
    for (int& x : a)
        if (__lg(x) < p) {
            bool ok = 1;
            int y = x;
            while (((y & 1) or (y & 2 ^ 2)) and y) {
                y >>= (y & 1 ? 1 : 2);
                ok &= !binary_search(a.begin(), a.end(), y);
            }
            dp[__lg(x)] += ok;
        }

    for (int i = 0; i < p; i++) {
        if (i - 2 >= 0)
            add(dp[i], dp[i - 2]);
        if (i - 1 >= 0)
            add(dp[i], dp[i - 1]);
    }
    for (int i = 1; i < p; i++)
        add(dp[i], dp[i - 1]);
    cout << dp.back() << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}