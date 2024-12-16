#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<array<int, 2>> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i],
        pref[i + 1][i & 1] += a[i];

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= 1; j++)
            ans = max(ans, pref[n][j] - pref[i][j] + pref[i][!j]);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}