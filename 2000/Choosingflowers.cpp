#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    v<array<int, 2>> a(m);
    for (auto& x : a)
        cin >> x[0] >> x[1];
    sort(a.begin(), a.end());
    v<int> pref(m + 1);
    for (int i = 0; i < m; i++)
        pref[i + 1] = pref[i] + a[i][0];

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int curr = a[i][0];
        int x = n - 1;
        int mxB = a[i][1];

        auto it = lower_bound(a.begin(), a.end(),
            array<int, 2>{mxB, 0});

        int r = m;
        int l = it - a.begin();
        if (r - l > x) l = r - x;

        curr += pref[r] - pref[l];
        if (i >= l)
            curr -= a[i][0], x++;
        x -= r - l;

        curr += x * mxB;
        ans = max(ans, curr);
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