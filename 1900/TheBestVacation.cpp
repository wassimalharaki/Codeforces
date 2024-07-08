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
    int n, x; cin >> n >> x;

    v<int> a(n);
    for (int& y : a) cin >> y;
    for (int i = 0; i < n; i++)
        a.push_back(a[i]);
    
    v<int> sz_pref(2 * n + 1), val_pref(2 * n + 1);
    partial_sum(a.begin(), a.end(), sz_pref.begin() + 1);
    for (int i = 1; i <= 2 * n; i++)
        val_pref[i] = val_pref[i - 1] + a[i - 1] * (a[i - 1] + 1) / 2;
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j = lower_bound(sz_pref.begin(), sz_pref.end(), sz_pref[i] + x) - sz_pref.begin();
        int left = a[i] - 1;
        int right = sz_pref[j] - sz_pref[i] - x;
        int use = x - sz_pref[j - 1] + sz_pref[i];
        int curr = val_pref[j - 1] - val_pref[i] + use * (use + 1) / 2;
        int push = min(left, right);
        curr += (2 * use + push + 1) * push / 2 - push * (push + 1) / 2;
        ans = max(ans, curr);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}