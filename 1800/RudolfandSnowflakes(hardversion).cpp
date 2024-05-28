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

set<int> ok;

void solve() {
    int n; cin >> n;
    if (ok.count(n)) {
        cout << "YES" << nl;
        return;
    }

    int lo = 1e5, hi = 1e9;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int val = 1 + mid + mid * mid;

        if (val == n) {
            cout << "YES" << nl;
            return;
        }
        else if (val > n)
            hi = mid - 1;
        else 
            lo = mid + 1;
    }
    cout << "NO" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int k = 2; k < 1e6; k++) {
        int sum = 1 + k + k * k;
        int curr = k * k;
        for (int x = 3; 1; x++) {
            ok.insert(sum);
            int a = LLONG_MAX / curr;
            if (a < k) break;
            curr *= k;
            if (curr >= 1e18) break;
            sum += curr;
            if (sum >= 1e18) break;
        }
    }

    int T = 1;
    cin >> T;
    while (T--) solve();
}