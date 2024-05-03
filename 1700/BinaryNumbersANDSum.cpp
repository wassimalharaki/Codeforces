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

// O(log(b))
int binpow(int a, int b, const int m = mod) {
    a %= m;
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
 
    if (n > m)
        t = string(n - m, '0') + t;
    else if (n < m)
        s = string(m - n, '0') + s;
    n = m = max(n, m);
 
    int ans = 0, ones = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] == '1') ones++;
        if (s[i] == '1')
            ans = (ans + ones * binpow(2, n - i - 1) % mod) % mod;
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}