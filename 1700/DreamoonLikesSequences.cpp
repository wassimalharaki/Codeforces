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
    int d, m; cin >> d >> m;

    v<int> blocks;
    for (int i = 0; i < 31; i++) {
        int l = (1 << i);
        int r = (1 << (i + 1)) - 1;
        if (l > d) break;
        r = min(r, d);
        blocks.push_back(r - l + 1);
    }

    int ans = 1;
    for (int& x : blocks)
        ans = (ans + ans * x) % m;
    cout << (ans - 1 + m) % m << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}