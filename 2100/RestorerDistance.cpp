#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    z = min(z, x + y);

    v<int> a(n);
    for (int& k : a) cin >> k;
    sort(a.begin(), a.end());
    v<int> pref(n + 1);
    partial_sum(a.begin(), a.end(), pref.begin() + 1);

    auto get = [&](int k) -> int {
        int i = lower_bound(a.begin(), a.end(), k) - a.begin();
        int l = pref[i], r = pref[n] - pref[i];
        int xtra = r - (n - i) * k;
        int need = i * k - l;
        int sub = min(xtra, need);
        xtra -= sub, need -= sub;
        return need * x + xtra * y + sub * z;
    };

    int ans = LLONG_MAX;
    for (int i = 0; i < n; i++)
        ans = min(ans, get(a[i]));
    {
        int sum = accumulate(a.begin(), a.end(), 0ll);
        ans = min(ans, get(sum / n));
        ans = min(ans, get((sum + n - 1) / n));
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