#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;

    v<int> cnt(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a < n) cnt[a]++;
    }

    int mex = 0;
    for (int i = 0; i < n; i++)
        if (cnt[i]) mex++;
        else break;

    v<int> dp(n + 1, -1);
    dp[0] = 0;
    auto f = [&](int x, auto&& f) -> int {
        if (dp[x] != -1) return dp[x];
        int ans = 1e9;
        for (int i = 0; i < x; i++)
            ans = min(ans, x * (cnt[i] - 1) + i + f(i, f));
        return dp[x] = ans;
    };
    cout << f(mex, f) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}