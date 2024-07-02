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

    int prev = 0;
    bool ok = 1;
    v<int> a, sz;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        if (not ok) continue;
        if (x == 1) {
            prev++;
            if (prev > 1e18) {
                ok = 0;
                continue;
            }
            a.push_back(y);
            sz.push_back(prev);
        }
        else {
            a.push_back(-1);
            int c = sz.back();
            if ((long double) log10(c) + log10(y) > 18) {
                sz.push_back(1e18);
                ok = 0;
                continue;
            }
            prev += c * y;
            sz.push_back(prev);
        }
    }

    auto prod = [&](int k, auto&& prod) -> int {
        auto it = lower_bound(sz.begin(), sz.end(), k);
        if (it == sz.begin())
            return a[0];
        int i = it - sz.begin();
        int b = *(--it);
        if (a[i] >= 0)
            return a[i];
        else
            return prod((k - 1) % b + 1, prod);
    };

    while (q--) {
        int k; cin >> k;
        cout << prod(k, prod) << " ";
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}