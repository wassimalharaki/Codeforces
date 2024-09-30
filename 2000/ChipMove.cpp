#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int mod = 998244353;

void add(int& a, int b) {
    a += b;
    while (a >= mod)
        a -= mod;
}

void solve() {
    int n, k; cin >> n >> k;

    v<int> ans(n + 1), dp(n + 1);
    ans[0] = dp[0] = 1;
    for (int i = 0; i + k <= n; i += k++) {
        for (int j = 0; j < k; j++) {
            int x = 0, y = 0;
            for (int r = j; r <= n; r += k) {
                y = dp[r];
                dp[r] = x;
                add(ans[r], x);
                add(x, y);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}