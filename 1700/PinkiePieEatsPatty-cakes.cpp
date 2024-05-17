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

    v<int> cnt(n + 1);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mx = max(mx, ++cnt[x]);
    }

    int x = 0;
    for (int& y : cnt)
        if (y == mx)
            x++;
            
    cout << (n - x) / (mx - 1) - 1 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}