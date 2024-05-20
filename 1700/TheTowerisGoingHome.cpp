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
    int n, m; cin >> n >> m;

    v<int> vert(n);
    for (int& x : vert) cin >> x;
    sort(vert.begin(), vert.end());
    vert.push_back(1e9);

    v<int> horz;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (a != 1) continue;
        horz.push_back(b);
    }
    sort(horz.begin(), horz.end());

    int ans = 1e9;
    for (int i = 0; i <= n; i++) {
        auto it = lower_bound(horz.begin(), horz.end(), vert[i]);
        ans = min(ans, i + horz.end() - it);
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