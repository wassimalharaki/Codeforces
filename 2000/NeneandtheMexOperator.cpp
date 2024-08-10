#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;
    v<int> a(n);
    for (int& x : a) cin >> x;

    v<pair<int, v<array<int, 2>>>> dp(n + 1);
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i];
        dp[i + 1].first += a[i];

        for (int j = i; j >= 0; j--) {
            int x = i - j + 1;
            if (x * x + dp[j].first > dp[i + 1].first) {
                dp[i + 1].second = dp[j].second;
                dp[i + 1].second.push_back({j + 1, i + 1});
                dp[i + 1].first = x * x + dp[j].first;
            }
        }
    }

    v<array<int, 2>> ops;
    auto m_i = [&](int l, int r, auto&& m_i) -> void {
        if (l == r) {
            return;
        }
        m_i(l, r - 1, m_i);
        ops.push_back({l, r});
        ops.push_back({l, r - 1});
        m_i(l, r - 1, m_i);
    };
    for (int i = 0; i < dp[n].second.size(); i++) {
        int l = dp[n].second[i][0], r = dp[n].second[i][1];
        bool have_zero = 0;
        for (int j = l - 1; j < r; j++)
            if (a[j] == 0)
                have_zero = 1;

        ops.push_back({l, r});
        if (have_zero)
            ops.push_back({l, r});

        m_i(l, r, m_i);
        ops.push_back({l, r});
    }
    cout << dp[n].first << " " << ops.size() << nl;
    for (int i = 0; i < ops.size(); i++)
        cout << ops[i][0] << " " << ops[i][1] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}