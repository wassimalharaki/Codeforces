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

    v<pair<int, int>> nums(n);
    for (auto& p : nums)
        cin >> p.first;
    for (auto& p : nums)
        cin >> p.second;
    sort(all(nums));

    v<pair<int, int>> fix{nums[0]};
    for (int i = 1; i < n; i++)
        if (nums[i].first == fix.back().first)
            fix.back().second = max(fix.back().second, nums[i].second);
        else
            fix.push_back(nums[i]);
    
    nums = fix;
    n = nums.size();
    
    if (n == 1) {
        cout << nums[0].first << nl;
        return;
    }

    v<int> left(n), right(n);
    int x = 0;
    for (int i = 0; i < n; i++) {
        x = max(x, nums[i].second);
        left[i] = x;
        if (i + 1 < n)
            x += nums[i + 1].first - nums[i].first;
    }

    x = 0;
    for (int i = n - 1; i >= 0; i--) {
        x = max(x, nums[i].second);
        right[i] = x;
        if (i - 1 >= 0)
            x += nums[i].first - nums[i - 1].first;
    }

    double min_diff, time, ans;
    min_diff = time = INT_MAX;
    for (int i = 0; i < n; i++) {
        double diff = abs(right[i] - left[i]) / 2.;
        if (diff < min_diff) {
            min_diff = diff;
            diff = (right[i] - left[i]) / 2.;
            time = (right[i] + left[i]) / 2.;
            ans = nums[i].first + diff;
        }
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << setprecision(10) << fixed;
    int T = 1;
    cin >> T;
    while (T--) solve();
}