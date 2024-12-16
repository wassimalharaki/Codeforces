#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 26 * 200;

void solve() {
    int n, m; cin >> n >> m;

    v dp(m + 1, v<int>(N, INT_MIN)); dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        int z; cin >> z;
        int x = 0, y = 0;
        while ((z & 1) ^ 1) z >>= 1, x++;
        while (z % 5 == 0) z /= 5, y++;

        for (int j = m - 1; j >= 0; j--)
            for (int k = 0; k + y < N; k++)
                dp[j + 1][k + y] = max(dp[j + 1][k + y], dp[j][k] + x);
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
        ans = max(ans, min(i, dp[m][i]));
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}