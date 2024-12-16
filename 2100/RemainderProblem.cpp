#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 5e5 + 1;
const int M = 0.5 * sqrt(N);

void solve() {
    int q; cin >> q;

    v dp(M, v<int>(M));
    v<int> a(N);

    while (q--) {
        int t, x, y; cin >> t >> x >> y;
        if (t == 1) {
            a[x] += y;
            for (int i = 1; i < M; i++)
                dp[i][x % i] += y;
        }
        else if (x >= M) {
            int ans = 0;
            for (int i = y; i < N; i += x)
                ans += a[i];
            cout << ans << nl;
        }
        else
            cout << dp[x][y] << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}