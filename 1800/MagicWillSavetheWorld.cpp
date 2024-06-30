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

const int N = 1e6 + 1;

void solve() {
    int w, f, n; cin >> w >> f >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    int x = accumulate(a.begin(), a.end(), 0ll);

    bitset<N> dp; dp[0] = 1;
    for (int& x : a)
        dp |= (dp << x);
    
    int ans = 1e18;
    for (int i = 0; i <= x; i++)
        if (dp[i])
            ans = min({
                ans,
                max((i + w - 1) / w, (x - i + f - 1) / f),
                max((i + f - 1) / f, (x - i + w - 1) / w)
            });
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}