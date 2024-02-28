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
    int n, m; cin >> n >> m;

    v<array<int, 3>> nums(n);
    for (auto& a : nums)
        cin >> a[0] >> a[1] >> a[2];
    
    int l = m, r = m, prev = 0;
    auto intersect = [&](int lb, int rb) {
        l = max(l, lb);
        r = min(r, rb);
    };
    for (int i = 0; i < n; i++) {
        int diff = nums[i][0] - prev;
        prev = nums[i][0];
        l -= diff, r += diff;
        intersect(nums[i][1], nums[i][2]);
        if (l > r) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}