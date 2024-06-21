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

    v<int> left(n), right(n);
    left[0] = 1;
    for (int i = 1; i < n; i++)
        left[i] = left[i - 1] + (a[i] >= a[i - 1]),
        right[n - i - 1] = right[n - i] + (a[n - i - 1] >= a[n - i]);
    
    int ans = min(left[n - 1], right[0]);
    for (int i = 1; i < n - 1; i++)
        ans = min(ans, left[i] + right[i + 1]);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}