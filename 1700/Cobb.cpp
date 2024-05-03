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

    v<int> a(n);
    for (int& x : a) cin >> x;

    int ans = -1e9;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < i + 110 and j < n; j++)
            ans = max(ans, (i + 1) * (j + 1) - k * (a[i] | a[j]));
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}