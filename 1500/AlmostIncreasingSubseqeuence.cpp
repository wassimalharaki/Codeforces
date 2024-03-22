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
    int n, q; cin >> n >> q;

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    v<int> mark(n);
    for (int i = 0; i < n - 2; i++)
        if (nums[i] >= nums[i + 1] and nums[i + 1] >= nums[i + 2])
            mark[i] = 1;

    v<int> prefix(n + 1);
    partial_sum(all(mark), prefix.begin() + 1);

    while (q--) {
        int l, r; cin >> l >> r;
        int ans = r - l + 1;
        if (r - 2 >= 0 and r - 2 >= l)
            ans -= prefix[r - 2] - prefix[l - 1];
        cout << ans << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}