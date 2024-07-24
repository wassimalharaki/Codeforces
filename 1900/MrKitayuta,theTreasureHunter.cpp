#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

const int N = 3e4 + 1;

void solve() {
    int n, d; cin >> n >> d;

    v<int> cnt(N);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    v<array<int, 2>> a(N, {INT_MAX, INT_MIN});
    a[0] = {d, d};
    for (int i = 0; i < N; i++)
        for (int j = a[i][0]; j <= a[i][1]; j++)
            a[i + j][0] = min(a[i + j][0], max(j - 1, 1)),
            a[i + j][1] = max(a[i + j][1], min(j + 1, N - (i + j + 1)));
    
    v<array<int, 400>> dp(N);
    for (int i = N - 1; i >= 0; i--) {
        dp[i].fill(cnt[i]);
        for (int j = a[i][0]; j <= a[i][1]; j++)
            dp[i][j - a[i][0]] = max(dp[i][j - a[i][0]], cnt[i] + max({
                dp[i + j][j - a[i + j][0]],
                (j - 1 ? dp[i + j][j - 1 - a[i + j][0]] : 0),
                (j + 1 < N - (i + j + 1) ? dp[i + j][j + 1 - a[i + j][0]] : 0)
            }));
    }
    cout << dp[0][0] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}