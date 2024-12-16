#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    v<int> a(n);
    for (int& x : a) cin >> x;

    auto check = [&](int k) -> bool {
        v<int> b(n);
        for (int i = 0; i < n; i++)
            b[i] = a[i] >= k ? 1 : -1;
        
        v<int> pref(n + 1);
        int curr = 0;
        for (int i = 0; i < n; i++) {
            curr += b[i];
            pref[i + 1] = min(pref[i], curr);
            if (i >= m - 1 and curr - pref[i - m + 1] > 0)
                return 1;
        }
        return 0;
    };

    int lo = 1, hi = n, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (check(mid))
            lo = mid + 1, ans = mid;
        else
            hi = mid - 1;
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