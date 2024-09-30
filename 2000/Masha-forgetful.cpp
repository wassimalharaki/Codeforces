#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    map<string, array<int, 3>> a;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j + 1 < m; j++)
            a[s.substr(j, 2)] = {j + 1, j + 2, i + 1};
        for (int j = 0; j + 2 < m; j++)
            a[s.substr(j, 3)] = {j + 1, j + 3, i + 1};
    }
    string s; cin >> s;

    v<array<int, 2>> dp(m + 1); dp[0] = {1, 0};
    for (int i = 0; i < m; i++)
        for (int j = i - 2; j <= i - 1; j++)
            if (j >= 0 and dp[j][0] and a.count(s.substr(j, i - j + 1)))
                dp[i + 1] = {1, j};
    if (not dp[m][0]) {
        cout << -1 << nl;
        return;
    }

    int i = m;
    v<array<int, 3>> ans;
    while (i) {
        ans.push_back(a[s.substr(dp[i][1], i - dp[i][1])]);
        i = dp[i][1];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << nl;
    for (auto& [l, r, j] : ans)
        cout << l << " " << r << " " << j << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}