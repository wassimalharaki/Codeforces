#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m, k; cin >> n >> m >> k;

    v<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());
    a = v<int>(a.begin(), a.begin() + k);
    n = k;

    v<int> dp(n + 1), pref(n + 1);
    partial_sum(a.begin(), a.end(), dp.begin() + 1);
    partial_sum(a.begin(), a.end(), pref.begin() + 1);

    v<array<int, 2>> b(m);
    for (auto& [l, r] : b)
        cin >> r >> l;
    sort(b.begin(), b.end(), [](auto& x, auto& y) {
        return x[1] < y[1];
    });
    for (int i = 0; i <= n; i++)
        for (auto& [l, r] : b)
            if (i + r <= n)
                dp[i + r] = min(dp[i + r], dp[i] + pref[i + r] - pref[i + l]);
    cout << dp[n] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}