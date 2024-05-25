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

    v<int> a(n);
    for (int& x : a) cin >> x;

    v<int> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; i++)
        dp[i] = dp[i - 1] + 1 + (a[i] != a[i - 1]) * i;
    int ans = accumulate(dp.begin(), dp.end(), 0ll);

    while (m--) {
        int i, x; cin >> i >> x; i--;
        if (n == 1) {
            cout << 1 << nl;
            continue;
        }
        if (a[i] == x) {
            cout << ans << nl;
            continue;
        }
        if (i == 0) {
            if (a[i] == a[i + 1])
                ans += n - i - 1;
            else if (x == a[i + 1]) 
                ans -= n - i - 1;
            a[i] = x;
            cout << ans << nl;
        }
        else if (i == n - 1) {
            if (a[i] == a[i - 1])
                ans += i;
            else if (x == a[i - 1])
                ans -= i;
            a[i] = x;
            cout << ans << nl;
        }
        else {
            int l = i, r = n - i - 1, y = 0;
            if (a[i] == a[i - 1])
                ans += i, y++;
            else if (x == a[i - 1])
                ans -= i, y--;
            
            if (a[i] == a[i + 1])
                ans += n - i - 1, y++;
            else if (x == a[i + 1])
                ans -= n - i - 1, y--;
            a[i] = x;
            ans += r * l * y;
            cout << ans << nl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}