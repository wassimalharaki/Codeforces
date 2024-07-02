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
    int n, b, x; cin >> n >> b >> x;
    
    v<int> a(n);
    for (int& y : a) cin >> y;

    auto get = [&](int k) -> int {
        int ans = 0;
        for (int y : a) {
            int n = min(k, y);
            v<int> splits(n);
            int i = 0;
            while (y--)
                splits[i++ % n]++;
            v<int> pref(n);
            partial_sum(splits.begin(), splits.end(), pref.begin());
            for (int i = 0; i < n; i++)
                ans += splits[i] * (pref[n - 1] - pref[i]) * b;
        }
        return ans - (k - 1) * x;
    };
    
    int lo = 1, hi = *max_element(a.begin(), a.end()), ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int prev = get(max(1ll, mid - 1));
        int curr = get(mid);

        if (curr >= prev)
            ans = max(ans, curr), lo = mid + 1;
        else
            hi = mid - 1;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}