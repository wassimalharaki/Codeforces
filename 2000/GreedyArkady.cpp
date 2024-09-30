#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, k, m, d;
    cin >> n >> k >> m >> d;

    auto get = [&](int x) {
        __int128 den = __int128(k) * x;
        return n / den + (n % den >= x);
    };

   int ans = 0;
    for (int i = 1; i <= d; i++) {
        int lo = 1, hi = 1e18, maxx = 1;
        while (lo <= hi) {
            int x = (lo + hi) / 2;

            if (get(x) >= i)
                maxx = x, lo = x + 1;
            else
                hi = x - 1;
        }
        maxx = min(maxx, m);
        if (get(maxx) == i)
            ans = max(ans, maxx * i);
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}