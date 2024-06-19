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
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    array<int, 60> bits; bits.fill(0);
    for (int& x : a)
        for (int i = 0; i < 60; i++)
            if ((1ll << i) & x)
                bits[i]++;
    
    v<int> b(n), c(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 60; j++)
            if ((1ll << j) & a[i]) {
                add(b[i], (1ll << j) % mod * bits[j]);
                add(c[i], (1ll << j) % mod * n);
            }
            else
                add(c[i], (1ll << j) % mod * bits[j]);

    int ans = 0;
    for (int i = 0; i < n; i++)
        add(ans, b[i] * c[i] % mod);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}