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

    auto get = [&](int x) {
        int lo = 0, hi = 1e15, ans;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            int ones = (mid + 1) / 2;
            int twos = mid / 2;

            bool ok = 1;
            for (int i = 0; i < n; i++) {
                int need = x - a[i];

                int sub = min(twos, need / 2);
                twos -= sub;
                need -= sub * 2;

                sub = min(ones, need);
                ones -= sub;
                need -= sub;
                if (need) ok = 0;
            }

            if (ok)
                ans = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
        return ans;
    };

    int x = *max_element(a.begin(), a.end());
    cout << min(get(x), get(x + 1)) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}