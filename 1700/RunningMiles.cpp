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
    
    v<int> left(n), right(n, -1e9);
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], a[i - 1] + i);
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], a[i + 1] - (i + 2));
    
    int ans = 0;
    for (int i = 1; i < n - 1; i++)
        ans = max(ans, left[i] + a[i] + right[i]);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}