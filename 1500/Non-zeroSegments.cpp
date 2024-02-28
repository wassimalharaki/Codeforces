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

    int ans = 0, curr = 0;
    set<int> seen;
    for (int i = 0; i < n; i++) {
        curr += nums[i];
        if (seen.count(curr) or curr == 0) {
            ans++;
            seen.clear();
            curr = nums[i];
        }
        seen.insert(curr);
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}