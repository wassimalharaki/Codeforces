#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, x; cin >> n >> x;

    v<int> a(n);
    for (int& y : a) cin >> y;

    v<int> dp_no_op(n), pref_no_op(n + 1), suff_op(n);
    pref_no_op[1] = a[0];
    dp_no_op[0] = max(a[0], 0ll);
    suff_op[0] = x * a[0];

    int curr = a[0], mn = min(a[0], 0ll);
    for (int i = 1; i < n; i++) {
        curr += a[i];
        mn = min(mn, curr);

        pref_no_op[i + 1] = curr;
        dp_no_op[i] = curr - mn;
        suff_op[i] = a[i] * x + max(suff_op[i - 1], dp_no_op[i - 1]);
    }

    int ans = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, suff_op[i] - pref_no_op[i + 1]);
        ans = max(ans, pref_no_op[i + 1] + mx);
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