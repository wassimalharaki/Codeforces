#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;

    array<int, 2> z{-1, -1};
    v a(n + 1, v<array<int, 2>>(n + 1, {0, 0}));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            if (x == 0)
                z = {i, j};
            else if (x) {
                while (x & 1 ^ 1)
                    x >>= 1, a[i][j][0]++;
                while (x % 5 == 0)
                    x /= 5, a[i][j][1]++;
            }
        }
    
    v dp(n + 1, v<array<int, 2>>(n + 1, {INT_MAX, 0}));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == 1 and j == 1)
                dp[i][j] = {a[i][j][0], -1};
            else if (dp[i - 1][j][0] < dp[i][j - 1][0])
                dp[i][j] = {dp[i - 1][j][0] + a[i][j][0], 1};
            else
                dp[i][j] = {dp[i][j - 1][0] + a[i][j][0], 0};

    int ans = dp[n][n][0];
    string s;
    for (int i = n, j = n; dp[i][j][1] != -1;)
        if (dp[i][j][1])
            s.push_back('D'), i--;
        else 
            s.push_back('R'), j--;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == 1 and j == 1)
                dp[i][j] = {a[i][j][1], -1};
            else if (dp[i - 1][j][0] < dp[i][j - 1][0])
                dp[i][j] = {dp[i - 1][j][0] + a[i][j][1], 1};
            else
                dp[i][j] = {dp[i][j - 1][0] + a[i][j][1], 0};
    
    if (dp[n][n][0] < ans) {
        ans = dp[n][n][0];
        s.clear();
        for (int i = n, j = n; dp[i][j][1] != -1;)
            if (dp[i][j][1])
                s.push_back('D'), i--;
            else 
                s.push_back('R'), j--;
    }
    reverse(s.begin(), s.end());

    if (z[0] == -1 or ans == 0)
        cout << ans << nl << s << nl;
    else {
        cout << 1 << nl;
        for (int i = 1; i < z[0]; i++)
            cout << 'D';
        for (int i = 1; i < z[1]; i++)
            cout << 'R';
        for (int i = z[0]; i < n; i++)
            cout << 'D';
        for (int i = z[1]; i < n; i++)
            cout << 'R';
        cout << nl;
        return;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}