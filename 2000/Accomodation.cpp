#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, m; cin >> n >> m;

    string s;
    int min = 0, max = 0;
    for (int k = 0; k < n; k++) {
        cin >> s;
        v<int> a(m);
        for (int i = 0; i < m; i++)
            a[i] = s[i] - '0';
        {
            int oo = 0;
            v<int> dead(m);
            for (int i = 0; i < m - 1 and oo < m / 4; i++)
                if (not dead[i] and not dead[i + 1] and
                        a[i] == a[i + 1] and a[i])
                    oo++, dead[i] = dead[i + 1] = 1;
            min += oo;
            for (int i = 0; i < m; i++)
                if (not dead[i])
                    min += a[i];
        }
        
        v<array<array<int, 2>, 2>> dp(m + 1);
        for (int i = 2; i <= m; i++) {
            int x = a[i - 2], y = a[i - 1];
            dp[i][1] = {INT_MIN, 0};

            if (dp[i - 1][0][0] >= dp[i - 1][1][0])
                dp[i][0] = {dp[i - 1][0][0], 0};
            else
                dp[i][0] = {dp[i - 1][1][0], 1};

            if (x == 1 and y == 1)
                continue;

            if (dp[i - 2][0][0] >= dp[i - 2][1][0]) {
                if (dp[i - 2][0][0] + 1 <= m / 4)
                    dp[i][1] = {dp[i - 2][0][0] + 1, 0};
            }
            else {
                if (dp[i - 2][1][0] + 1 <= m / 4)
                    dp[i][1] = {dp[i - 2][1][0] + 1, 1};
            }
        }

        v<int> dead(m);
        int cnt = std::max(dp[m][0][0], dp[m][1][0]);
        int j = dp[m][0][0] <= dp[m][1][0];
        for (int i = m; i;) {
            if (j) {
                j = dp[i][j][1];
                dead[i - 2] = dead[i - 1] = 1;
                max += a[i - 2] | a[i - 1];
                i -= 2;
            }
            else
                j = dp[i--][j][1];
        }
        for (int i = 0; i < m - 1 and cnt < m / 4; i++)
            if (not dead[i] and not dead[i + 1])
                cnt++, dead[i] = dead[i + 1] = 1, max += a[i] | a[i + 1];
        
        for (int i = 0; i < m; i++)
            if (not dead[i])
                max += a[i];
    }
    cout << min << " " << max << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}