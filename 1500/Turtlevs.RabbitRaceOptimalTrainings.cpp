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
 
    v<int> nums(n);
    for (int& a : nums) cin >> a;
 
    v<int> prefix(n + 1);
    partial_sum(all(nums), prefix.begin() + 1);
 
    int q; cin >> q;
    while (q--) {
        int l, u; cin >> l >> u;
        auto it = lower_bound(all(prefix), prefix[l - 1] + u);
        --it;
        int i = it - prefix.begin();
        int sum = *it - prefix[l - 1];
        int need = u - sum;
        if (i < n and nums[i] <= 2 * need)
            cout << i + 1 << " ";
        else
            cout << max(i, l) << " ";
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}