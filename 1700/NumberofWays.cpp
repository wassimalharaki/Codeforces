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
    int n; cin >> n;

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    v<int> prefix(n), suffix(n);
    partial_sum(nums.begin(), nums.end(), prefix.begin());
    reverse(nums.begin(), nums.end());
    partial_sum(nums.begin(), nums.end(), suffix.begin());
    reverse(nums.begin(), nums.end());

    map<int, v<int>> cnt;
    for (int i = 0; i < n; i++)
        cnt[suffix[i]].push_back(i);

    int ans = 0, sum = accumulate(nums.begin(), nums.end(), 0ll);
    for (int i = 1; i < n - 1; i++) {
        int left = prefix[i - 1], rem = sum - left;
        if ((rem & 1) or rem / 2 != left)
            continue;
        auto& a = cnt[rem / 2];
        auto it = upper_bound(a.begin(), a.end(), n - i - 2);
        ans += it - a.begin();
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