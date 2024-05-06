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

void solve() {
    int n, m; cin >> n >> m;
    v<int> dp1(n + 1);
    dp1[0] = 2; dp1[1] = 2;
    for (int i = 2; i <= n; i++)
        dp1[i] = (dp1[i - 1] + dp1[i - 2]) % mod;

    v<int> dp2(m + 1);
    dp2[0] = 2; dp2[1] = 2;
    for (int i = 2; i <= m; i++)
        dp2[i] = (dp2[i - 1] + dp2[i - 2]) % mod;
    cout << (dp1[n] + dp2[m] - 2) % mod << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}