#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

const int mod = 1e9 + 7;

void add(int& a, int b) {
    a = (a + b) % mod;
}

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> dp_a(n + 1, v<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        dp_a[i][1] = 1;
        for (int j = 2; j <= m; j++)
            add(dp_a[i][j], dp_a[i - 1][j] + dp_a[i][j - 1]);
    }

    v<v<int>> dp_b(n + 2, v<int>(m + 1));
    for (int i = n; i >= 1; i--) {
        dp_b[i][1] = 1;
        for (int j = 2; j <= m; j++)
            add(dp_b[i][j], dp_b[i + 1][j] + dp_b[i][j - 1]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            add(ans, dp_a[i][m] * dp_b[j][m] % mod);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}