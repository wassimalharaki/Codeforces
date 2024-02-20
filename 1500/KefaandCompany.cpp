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
    int n, d; cin >> n >> d;

    v<pair<int, int>> nums(n);
    for (auto& p : nums)
        cin >> p.first >> p.second;
    sort(all(nums));

    int ans = 0, curr = 0;
    int l = 0, r = 0;
    while (r < n)
        if (nums[r].first - nums[l].first >= d)
            curr -= nums[l++].second;
        else {
            curr += nums[r++].second;
            ans = max(ans, curr);
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