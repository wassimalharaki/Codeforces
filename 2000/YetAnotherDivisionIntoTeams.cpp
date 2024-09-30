#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<array<int, 2>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i][0], a[i][1] = i;
    sort(a.begin(), a.end());

    v<array<int, 2>> dp(n), pref(n);
    dp[0][0] = dp[1][0] = 1e18;
    pref[0] = pref[1] = {- a[0][0], -1};
    dp[2] = {a[2][0] - a[0][0], -1};
    for (int i = 3; i < n; i++) {
        pref[i - 2] = min(
            pref[i - 3],
            {dp[i - 3][0] - a[i - 2][0], i - 3}
        );
        dp[i] = pref[i - 2];
        dp[i][0] += a[i][0];
    }

    int j = n - 1, k = 1;
    v<int> ans(n);
    while (j != -1) {
        for (int i = dp[j][1] + 1; i <= j; i++)
            ans[a[i][1]] = k;
        k++, j = dp[j][1];
    }
    cout << dp.back()[0] << " " << k - 1 << nl;
    for (int& x : ans)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}