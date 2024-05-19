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
    int a, b; cin >> a >> b;
    if (a < b) swap(a, b);
    
    auto get = [&](int i) {
        return i - 1 + (a + i - 1) / i + (b + i - 1) / i;
    };

    int ans = LLONG_MAX;
    for (int i = 1; i * i <= 2 * (a + b); i++)
        ans = min(ans, get(i));
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}