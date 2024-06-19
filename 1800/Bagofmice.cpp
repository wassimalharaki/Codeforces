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
    int n, m; cin >> n >> m;

    v dp(n + 1, v(m + 1, array<double, 2>{-1, -1}));
    dp[0][0] = {1, 0};
    auto go = [&](int w, int b, bool alt, auto&& go) -> double {
        if (w < 0 or b < 0) return 0;
        if (dp[w][b][alt] != -1)
            return dp[w][b][alt];

        if (alt)
            return dp[w][b][alt] = (double) w / (w + b)
                + (double) b / (w + b) * (1 - go(w, b - 1, !alt, go));
        else {
            if (b + w == 1)
                return dp[w][b][alt] = 1;
                
            return dp[w][b][alt] = (double) w / (w + b) + (double) b / (w + b)
                * ((double) (b - 1) / (w + b - 1) * (1 - go(w, b - 2, !alt, go))
                + (double) w / (w + b - 1) * (1 - go(w - 1, b - 1, !alt, go)));
        }
    };
    cout << fixed << setprecision(9) << go(n, m, 1, go);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}