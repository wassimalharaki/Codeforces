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
    int n; cin >> n;

    v<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    int ans = 1, curr = a[0] * b[0], ok = b[0];
    for (int i = 1; i < n; i++) {
        ok = lcm(ok, b[i]);
        curr = gcd(curr, a[i] * b[i]);
        if (curr % ok) {
            ans++, curr = a[i] * b[i];
            ok = b[i];
        }
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}