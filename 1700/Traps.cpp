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
    int n, k; cin >> n >> k;

    v<array<int, 2>> a(n);
    v<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        b[i] = a[i][0];
        a[i][1] = n - i - 1;
    }
    sort(a.begin(), a.end(), [](auto& l, auto& r) {
        return -l[0] + l[1] < -r[0] + r[1];
    });

    int ans = - (k - 1) * k / 2;
    for (int i = 0; i < n; i++)
        ans += (i < k ? a[i][1] : a[i][0]);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}