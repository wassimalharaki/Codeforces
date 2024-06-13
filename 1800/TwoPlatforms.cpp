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
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        int y; cin >> y;
    }

    v<int> b(n);
    for (int i = 0; i < n; i++)
        b[i] = upper_bound(a.begin(), a.end(), a[i] + k) - (a.begin() + i);
    
    v<int> left(n + 1), right(n + 1);
    for (int i = 0; i < n; i++)
        left[i + 1] = max(left[i], b[i]),
        right[n - i - 1] = max(right[n - i], b[n - i - 1]);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = upper_bound(a.begin(), a.end(), a[i] + k);
        ans = max(ans, left[i + 1] + right[it - a.begin()]);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}