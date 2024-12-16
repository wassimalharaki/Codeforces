#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    v<int> a(n);
    v<v<int>> ind(n + 1);
    for (int& x : a) cin >> x;

    {
        v<int> b{a[0]};
        for (int i = 1; i < n; i++)
            if (a[i] != b.back())
                b.push_back(a[i]);
        a.swap(b);
        n = a.size();
    }

    for (int i = 0; i < n; i++)
        ind[a[i]].push_back(i);

    v<array<array<int, 2>, 2>> dp(n);
    dp[0] = {array{1, -1}, {1, -1}};
    for (int i = 1; i < n; i++) {
        if (dp[i - 1][0][0] + (a[i] != dp[i - 1][0][1]) <
                dp[i - 1][1][0] + (a[i] != dp[i - 1][1][1])) {
            dp[i][0][0] = dp[i - 1][0][0] + (a[i] != dp[i - 1][0][1]);
            dp[i][0][1] = dp[i - 1][0][1];
            dp[i][1][0] = dp[i - 1][0][0] + 1;
            dp[i][1][1] = a[i - 1];
        }
        else {
            dp[i][0][0] = dp[i - 1][1][0] + 1;
            dp[i][0][1] = a[i - 1];
            dp[i][1][0] = dp[i - 1][1][0] + (a[i] != dp[i - 1][1][1]);
            dp[i][1][1] = dp[i - 1][1][1];
        }

        auto it = lower_bound(ind[a[i]].begin(), ind[a[i]].end(), i);
        if (it == ind[a[i]].begin()) continue;

        int j = *(--it);
        {
            int cost = dp[j][0][0] + (i - j - 1);
            cost -= dp[j][0][1] == a[j + 1];

            if (cost < dp[i][0][0]) {
                dp[i][0][0] = cost;
                dp[i][0][1] = a[i - 1];
            }
        }

        {
            int cost = dp[j][1][0] + (i - j - 1);
            cost -= dp[j][1][1] == a[j + 1];
            if (cost < dp[i][1][0]) {
                dp[i][1][0] = cost;
                dp[i][1][1] = a[i - 1];
            }
        }
    }
    cout << min(dp[n - 1][0][0], dp[n - 1][1][0]) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}