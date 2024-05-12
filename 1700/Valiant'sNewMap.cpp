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

    v<v<int>> a(n, v<int>(m));
    for (auto& x : a)
        for (int& y : x)
            cin >> y;

    v<v<int>> pref(n + 1, v<int>(m + 1));
    
    auto query = [&](int i, int j, int k) {
        return pref[i][j] - pref[i - k][j]
             - pref[i][j - k] + pref[i - k][j - k];
    };

    auto check = [&](int k) -> bool {
        if (k > n or k > m) return 0;
        if (k * k > n * m) return 0;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                pref[i][j] = (a[i - 1][j - 1] >= k) + pref[i - 1][j]
                           + pref[i][j - 1] - pref[i - 1][j - 1];
        
        for (int i = k; i <= n; i++)
            for (int j = k; j <= m; j++)
                if (query(i, j, k) >= k * k)
                    return 1;
        
        return 0;
    };

    int lo = 1, hi = 1e3, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (check(mid))
            ans = mid, lo = mid + 1;
        else
            hi = mid - 1;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}