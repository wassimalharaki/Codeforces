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
    string s; cin >> s;
    int n = s.size();
    v<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = s[n - i - 1] - '0';

    int ans = 0, curr = 1, x = 0;
    for (int i = 0; i < n; i++) {
        add(ans, (a[i] * curr % mod) * ((n - i) * (n - i - 1) / 2 % mod));
        add(ans, a[i] * x);
        x = (x + (i + 1) * curr) % mod;
        curr = curr * 10 % mod;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}