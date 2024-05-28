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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ans = (a % 2 + b % 2 + c % 2 == 3);
    ans += a / 2 + b / 2 + c / 2 + d / 2;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}