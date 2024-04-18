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

int ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int x; cin >> x;
    return r - l + 1 - x;
}

void solve() {
    int n, t, k; cin >> n >> t >> k;

    int lo = 1, hi = n, ans;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (ask(1, mid) >= k)
            ans = mid, hi = mid - 1;
        else
            lo = mid + 1;
    }
    cout << "! " << ans << endl;
}

signed main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}