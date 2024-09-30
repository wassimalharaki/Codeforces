#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, k; cin >> n >> k;

    v<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());
    v<int> pref(n + 1);
    partial_sum(a.begin(), a.end(), pref.begin() + 1);

    auto check = [&](int d) -> bool {
        int z = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            int x = a[i], y = a[i] + d;
            int curr = i * x - pref[i];
            int j = upper_bound(a.begin(), a.end(), y) - a.begin();
            curr += pref[n] - pref[j] - (n - j) * y;
            z = min(z, curr);
        }
        for (int i = n - 1; i >= 0; i--) {
            int x = a[i], y = a[i] - d;
            int curr = pref[n] - pref[i] - (n - i) * x;
            int j = lower_bound(a.begin(), a.end(), y) - a.begin();
            curr += j * y - pref[j];
            z = min(z, curr);
        }
        return z <= k;
    };

    int lo = 0, hi = 1e9, ans = 1e9;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (check(mid))
            hi = mid - 1, ans = mid;
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