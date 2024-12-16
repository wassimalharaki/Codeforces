#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n, k; cin >> n >> k;

    auto check = [&](int x) -> bool {
        int ans = 0;
        array<int, 2> a{x, x + ((x & 1) ^ 1)};

        while (a[1] <= n and ans < k) {
            ans += a[1] - a[0] + 1;
            a[0] <<= 1;
            a[1] = (a[1] << 1) + 1;
        }
        if (ans < k) ans += max(0ll, n - a[0] + 1);
        return ans >= k;
    };

    int o = 1, e = 1;
    {
        int lo = 1, hi = n / 2;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (check(2 * mid))
                e = 2 * mid, lo = mid + 1;
            else
                hi = mid - 1;
        }
    }
    {
        int lo = 1, hi = (n - 1) / 2;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (check(2 * mid + 1))
                o = 2 * mid + 1, lo = mid + 1;
            else
                hi = mid - 1;
        }
    }
    cout << max(o, e) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}