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

    int ans = max(- *min_element(a.begin(), a.end()), 0ll);
    for (int& x : a) x += ans;

    ans += a[0];
    int curr = 0;
    for (int i = 1; i < n; i++)
        if (a[i] == 0)
            ans += curr * 3, curr = 0;
        else 
            curr += max(0ll, a[i] - a[i - 1]);
    ans += curr * 3 - min(curr, a[n - 1]) * 2;

    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}