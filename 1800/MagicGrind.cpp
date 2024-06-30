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
    int x = 0, y = n;

    v a(n, v<int>(n));
    while (y) {
        int m = 1 << __lg(y);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][n - y + j] = x++; 
        y -= m;
    }

    for (auto& x : a) {
        for (auto& y : x)
            cout << y << " ";
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}