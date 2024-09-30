#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int mod = 1e9 + 7;
void add(int& a, int b) {
    a += b;
    while (a >= mod)
        a -= mod;
}

void solve() {
    int r, g; cin >> r >> g;
    if (r < g) swap(r, g);

    auto check = [&](int k) -> bool {
        int x = r, y = g;
        for (int i = k; i; i--)
            if (x >= i)
                x -= i;
            else if (y >= i)
                y -= i;
            else
                return 0;
        return 1;
    };

    int lo = 1, hi = 4e5, h = 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (check(mid))
            lo = mid + 1, h = mid;
        else
            hi = mid - 1;
    }

    v<int> dp(r + 1); dp[0] = 1;
    for (int i = 1; i <= h; i++)
        for (int j = r - i; j >= 0; j--)
            add(dp[j + i], dp[j]);
    
    int ans = 0;
    for (int i = 0; i <= r; i++)
        if (g >= (h + 1) * h / 2 - i)
            add(ans, dp[i]);
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}