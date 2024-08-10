#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, x, y; cin >> n >> x >> y;
    string s, t; cin >> s >> t;

    v<int> fix;
    for (int i = 0; i < n; i++)
        if (s[i] != t[i])
            fix.push_back(i);

    if (fix.size() == 0)
        cout << 0 << nl;
    else if (fix.size() & 1)
        cout << -1 << nl;
    else if (fix.size() == 2) {
        if (fix[1] - fix[0] == 1)
            cout << min(x, 2 * y) << nl;
        else
            cout << min(y, (fix[1] - fix[0]) * x) << nl;
    }
    else if (x >= y)
        cout << (fix.size() >> 1) * y << nl;
    else {
        auto cost = [&](int i, int j) -> int {
            return min(y, (fix[i] - fix[j]) * x);
        };
        v<pair<int, int>> dp(fix.size());
        dp[0] = make_pair(0, 0);
        dp[1] = make_pair(cost(1, 0), 0);
        for (int i = 2; i < fix.size(); i++)
            if (i & 1) {
                int a = cost(i, i - 1) + dp[i - 2].first;
                int b = dp[i - 1].first + cost(i, dp[i - 1].second);
                if (a < b)
                    dp[i] = make_pair(a, i - 1);
                else
                    dp[i] = make_pair(b, dp[i - 1].second);
            }
            else {
                int a = dp[i - 1].first;
                int b = cost(i, i - 1) + dp[i - 2].first;
                if (a < b)
                    dp[i] = make_pair(a, i);
                else
                    dp[i] = make_pair(b, dp[i - 2].second);
            }
        cout << dp[dp.size() - 1].first << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}