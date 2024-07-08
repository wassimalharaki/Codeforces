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

const int N = 1e3;

void solve() {
    int n, m; cin >> n >> m;

    v<int> a(n);
    for (int& x : a) {
        cin >> x;
        x %= m;
    }
    sort(a.begin(), a.end());

    bitset<N> dp;
    for (int& x : a) {
        dp |= (dp << x) | (dp >> (m - x));
        dp[x] = 1;
    }
    cout << (dp[0] ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}