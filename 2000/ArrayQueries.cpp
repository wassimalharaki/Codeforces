#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    for (int& x : a) cin >> x;
    int q; cin >> q;

    int B = sqrt(n) + 1;
    v<v<array<int, 2>>> queries(B);
    v<int> ans(q);
    for (int i = 0; i < q; i++) {
        int p, k; cin >> p >> k;
        if (k < B)
            queries[k].push_back({p, i});
        else
            while (p <= n) {
                p += a[p - 1] + k;
                ans[i]++;
            }
    }

    v<int> dp(n);
    for (int k = 1; k < B; k++) {
        fill(dp.begin(), dp.end(), 1);
        for (int i = n; i; i--)
            if (i + a[i - 1] + k <= n)
                dp[i - 1] = 1 + dp[i + a[i - 1] + k - 1];
        for (auto& [p, i] : queries[k])
            ans[i] = dp[p - 1];
    }

    for (int& x : ans)
        cout << x << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}