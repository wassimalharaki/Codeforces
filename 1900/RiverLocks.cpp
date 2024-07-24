#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n), pref(n + 1);
    for (int& x : a) cin >> x;
    partial_sum(a.begin(), a.end(), pref.begin() + 1);

    v<int> w(n), pref_w(n + 1);
    for (int i = 0; i < n; i++)
        w[i] = (a[i] + pref[i] + i) / (i + 1);
    partial_sum(w.begin(), w.end(), pref_w.begin() + 1,
        [](int x, int y) {
            return max(x, y);
        });
    

    auto check = [&](int k, int t) -> bool {
        if (k * t < pref[n]) return 0;
        if (t < pref_w[k]) return 0;
        return 1;
    };

    map<int, int> have{{0, -1}};
    for (int i = 1; i <= n; i++) {

        int lo = 0, hi = LLONG_MAX / i, ans = 1e18;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (check(i, mid))
                ans = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }

        if (have.count(ans))
            have[ans] = min(have[ans], i);
        else
            have[ans] = i;
    }

    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        cout << (--have.upper_bound(t)) -> second << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}