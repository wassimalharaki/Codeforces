#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;

    set<int> miss;
    for (int i = 1; i <= n; i++)
        miss.insert(i);

    v<int> a(n);
    for (int& x : a) {
        cin >> x;
        miss.erase(x);
    }

    int o = 0, e = 0;
    for (int x : miss)
        x & 1 ? o++ : e++;
    
    v dp(n, v(n + 1, v(n + 1, array<int, 2>{-1, -1})));
    auto go = [&](int i, int j, int k, int p, auto&& go) -> int {
        if (j < 0 or k < 0) return 1e9;
        if (i < 0) return 0;
        if (dp[i][j][k][p] != -1) return dp[i][j][k][p];
        if (a[i])
            return dp[i][j][k][p] = ((a[i] ^ p) & 1)
                + go(i - 1, j, k, a[i], go);

        return dp[i][j][k][p] = min(
            (p & 1 ^ 1) + go(i - 1, j - 1, k, 1, go),
            (p & 1) + go(i - 1, j, k - 1, 0, go)
        );
    };
    cout << min(go(n - 1, o, e, 0, go), go(n - 1, o, e, 1, go));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}