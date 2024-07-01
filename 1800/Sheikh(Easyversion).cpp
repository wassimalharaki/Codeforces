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
    int n, q; cin >> n >> q;

    v<int> a(n);
    for (int& x : a) cin >> x;
    cin >> n >> n;

    int x = accumulate(a.begin(), a.end(), 0ll) 
        - accumulate(a.begin(), a.end(), 0ll, bit_xor<int>());

    int lo = 1, hi = n, l = 1, r = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        int sum = 0, _xor = 0;
        for (int i = 0; i < mid; i++) {
            sum += a[i];
            _xor ^= a[i];
        }

        if (sum - _xor == x)
            l = 1, r = mid;
        
        for (int i = mid; i < n; i++) {
            sum += a[i] - a[i - mid];
            _xor ^= a[i] ^ a[i - mid];
            if (sum - _xor == x)
                l = i - mid + 2, r = i + 1;
        }

        if (r - l + 1 == mid)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    cout << l << " " << r << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}