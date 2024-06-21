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
    v<int> a(n);
    for (int& x : a) cin >> x;
    int k; cin >> k;

    int imin = n - 1;
    v<int> suff(n);
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < a[imin])
            imin = i;
        suff[i] = imin;
    }

    v<int> b(n);
    b[imin] = k / a[imin];
    int prev = imin;
    k %= a[imin];

    while (imin < n - 1 and b[prev]) {
        imin = suff[imin + 1];
        int x = min(k / (a[imin] - a[prev]), b[prev]);
        b[prev] -= x, b[imin] += x;
        k -= x * (a[imin] - a[prev]);
        prev = imin;
    }

    v<int> ans(n); ans[n - 1] = b[n - 1];
    for (int i = n - 2; i >= 0; i--)
        ans[i] = ans[i + 1] + b[i];
    for (int& x : ans)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}