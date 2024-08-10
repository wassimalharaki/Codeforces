#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int r, s, p; cin >> r >> s >> p;

    v dp(r + 1, v(s + 1, v<long double>(p + 1, -1)));
    dp[r][s][p] = 1;

    auto go = [&](int i, int j, int k, auto&& go) -> double {
        if (i > r or j > s or k > p)
            return 0;
        if (dp[i][j][k] > -0.5)
            return dp[i][j][k];
        
        dp[i][j][k] = 0;
        if (i * (j + 1) + (j + 1) * k + k * i)
            dp[i][j][k] += go(i, j + 1, k, go) * double(i * (j + 1)) / (i * (j + 1) + (j + 1) * k + k * i);
        if (i * j + j * (k + 1) + (k + 1) * i)
            dp[i][j][k] += go(i, j, k + 1, go) * double(j * (k + 1)) / (i * j + j * (k + 1) + (k + 1) * i);
        if ((i + 1) * j + j * k + k * (i + 1))
            dp[i][j][k] += go(i + 1, j, k, go) * double(k * (i + 1)) / ((i + 1) * j + j * k + k * (i + 1));

        return dp[i][j][k];
    };

    double ans = 0;
    for (int i = 1; i <= r; i++)    
        ans += go(i, 0, 0, go);
    cout << fixed << setprecision(12) << ans << " ";

    ans = 0;
    for (int i = 1; i <= s; i++)
        ans += go(0, i, 0, go);
    cout << fixed << setprecision(12) << ans << " ";

    ans = 0;
    for (int i = 1; i <= p; i++)
        ans += go(0, 0, i, go);
    cout << fixed << setprecision(12) << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}