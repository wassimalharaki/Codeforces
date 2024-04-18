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

void solve() {
    int n; cin >> n;

    v<array<int, 2>> nums(n);
    for (auto& a : nums)
        cin >> a[0] >> a[1];

    auto check = [&](int k) -> bool {
        int x = k - 1, y = 0;
        for (int i = 0; i < n; i++)
            if (nums[i][0] >= x and nums[i][1] >= y)
                x--, y++;
        return y >= k;
    };
    
    int lo = 1, hi = n, ans;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (check(mid))
            lo = mid + 1, ans = mid;
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