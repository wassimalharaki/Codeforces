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

int sqrd(int x) {
    return x * x;
}

void solve() {
    int d, k; cin >> d >> k;

    int lo = 0, hi = (1e9 + k - 1) / k, a = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (2 * sqrd(mid * k) <= sqrd(d))
            a = mid, lo = mid + 1;
        else
            hi = mid - 1;
    }
    bool ok = sqrd((a + 1) * k) + sqrd(a * k) <= sqrd(d);
    cout << (ok ? "Ashish" : "Utkarsh") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}