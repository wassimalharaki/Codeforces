#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n), dp(n + 1);
    v<v<int>> b(n + 1);
    for (int& x : a) cin >> x;

    v<int> c{a[0]};
    for (int i = 1; i < n; i++)
        if (a[i] != c.back())
            c.push_back(a[i]);
    int m = (a = c).size();

    for (int i = 0; i < m; i++)
        b[a[i]].push_back(i);

    for (int i = 1; i <= n; i++) {
        dp[i] += dp[i - 1];
        for (int& j : b[i]) {
            int l = j ? a[j - 1] : 0;
            int r = j + 1 < m ? a[j + 1] : 0;
            if (l <= i and r <= i)
                dp[i] -= min(l, r);
            dp[i] += i - max(l < i ? l : 0, r < i ? r : 0);
        }
    }
    cout << accumulate(dp.begin(), dp.end(), 0ll) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}