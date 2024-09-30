#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    {
        string t{s[0]};
        for (int i = 1; i < n; i++)
            if (s[i] != t.back())
                t.push_back(s[i]);
        t.swap(s);
        n = s.size();
    }

    v<v<int>> dp(n, v<int>(n));
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 0; j + i < n; j++) {
            dp[j][j + i] = min(
                dp[j + 1][j + i] + 1,
                dp[j][j + i - 1] + 1
            );
            for (int k = j + 1; k < j + i; k++)
                dp[j][j + i] = min({
                    dp[j][j + i],
                    dp[j + 1][k] + dp[k + 1][j + i] + (s[j] != s[k + 1]),
                    dp[j][k - 1] + dp[k][j + i - 1] + (s[j + i] != s[k - 1])
                });
        }
    cout << dp[0][n - 1] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}