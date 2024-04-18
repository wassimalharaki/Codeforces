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
    int n, k; cin >> n >> k;
    
    v<int> nums(n);
    for (int& a : nums) cin >> a;

    int l = nums[0] - k + 1, r = nums[0] + k - 1;
    for (int i = 1; i < n - 1; i++) {
        if (nums[i] > r) {
            cout << "NO" << nl;
            return;
        }
        if (nums[i] + k - 1 < l) {
            cout << "NO" << nl;
            return;
        }
        l = max(l - k + 1, nums[i] - k + 1);
        r = min(r + k - 1, nums[i] + 2 * (k - 1));
    }
    cout << (nums.back() >= l and nums.back() <= r ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}