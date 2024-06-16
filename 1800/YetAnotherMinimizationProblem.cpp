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

    int ans = 0;
    v<int> a(n), b(n);
    for (int& x : a) {
        cin >> x;
        ans += (n - 1) * x * x;
    }
    for (int& x : b) {
        cin >> x;
        ans += (n - 1) * x * x;
    }

    map<array<int, 2>, int> dp, next;
    dp[{0, 0}] = 0;
    for (int i = 0; i < n; i++) {
        next.clear();
        for (auto& [z, val] : dp) {
            array<int, 2> x(z), y(z);
            x[0] += a[i], x[1] += b[i];
            y[0] += b[i], y[1] += a[i];
            
            if (next.count(x))
                next[x] = min(next[x], val + 2 * a[i] * z[0] + 2 * b[i] * z[1]);
            else
                next[x] = val + 2 * a[i] * z[0] + 2 * b[i] * z[1];
            
            if (next.count(y))
                next[y] = min(next[y], val + 2 * a[i] * z[1] + 2 * b[i] * z[0]);
            else
                next[y] = val + 2 * a[i] * z[1] + 2 * b[i] * z[0];
        }
        dp.swap(next);
    }

    int x = 1e9;
    for (auto& [key, val] : dp)
        x = min(x, val);
    cout << ans + x << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}