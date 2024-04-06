#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

int f(int a, int b, int c, int d) {
    return abs(b - a) * abs(b - a) + abs(d - c) * abs(d - c);
}

void solve() {
    int n, k; cin >> n >> k;

    v<v<int>> ans(n, v<int>(n));
    int per = k / n, extra = k % n;
    for (int j = 0; j < n; j++) {
        int x = per + (extra-- > 0);
        for (int i = 0; i < x; i++)
            ans[(i + j) % n][j] = 1;
    }

    v<int> r(n), c(n);
    for (int i = 0; i < n; i++) {
        r[i] = accumulate(all(ans[i]), 0ll);
        for (int j = 0; j < n; j++)
            c[i] += ans[j][i];
    }
    sort(all(r)); sort(all(c));

    cout << f(r[0], r.back(), c[0], c.back()) << nl;
    for (auto& a : ans) {
        for (int& b : a)
            cout << b;
        cout << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}