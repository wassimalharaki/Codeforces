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
    int n, m, k; cin >> n >> m >> k;
 
    vector<int> a(n);
    for (int& x : a) cin >> x;
 
    int lo = 0, hi = n, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
 
        int cnt = 0, rem = 0;
        for (int i = mid; i < n; i++) {
            if (a[i] > rem) {
                cnt++;
                rem = k - a[i];
            }
            else
                rem -= a[i];
        }
 
        if (cnt <= m)
            hi = mid - 1, ans = n - mid;
        else
            lo = mid + 1;
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