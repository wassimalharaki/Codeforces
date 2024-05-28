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

    if (n == 1) {
        cout << -1 << nl;
        return;
    }

    v<int> fwd_pfx(n + 1), bwd_pfx(n + 1);
    partial_sum(nums.begin(), nums.end(), 1 + fwd_pfx.begin());
    reverse(nums.begin(), nums.end());
    partial_sum(nums.begin(), nums.end(), 1 + bwd_pfx.begin());
    reverse(nums.begin(), nums.end());

    v<int> eats;
    for (int i = 0; i < n; i++)
        if (i == 0) {
            if (nums[i] > nums[i + 1])
                eats.push_back(i);
        }
        else if (i == n - 1) {
            if (nums[i] > nums[i - 1])
                eats.push_back(i);
        }
        else {
            if (nums[i] > nums[i - 1] or nums[i] > nums[i + 1])
                eats.push_back(i);
        }
    
    if (eats.empty()) {
        for (int i = 0; i < n; i++)
            cout << -1 << " ";
        cout << nl;
        return;
    }

    
    for (int i = 0; i < n; i++)
        if (i == 0) {
            auto it = upper_bound(eats.begin(), eats.end(), i);
            int sum = fwd_pfx[n] - fwd_pfx[i + 1];
            if (it == eats.end() or sum <= nums[i]) {
                cout << -1 << " ";
                continue;
            }

            int next_eat = *it;
            if (nums[next_eat] <= nums[next_eat - 1])
                next_eat++;
            int j = upper_bound(fwd_pfx.begin(), fwd_pfx.end(), fwd_pfx[i + 1] + nums[i]) - fwd_pfx.begin() - 1;
            cout << max(next_eat - i, j - i) << " ";
        }
        else if (i == n - 1) {
            auto it = lower_bound(eats.begin(), eats.end(), i);
            int sum = fwd_pfx[i];
            if (it == eats.begin() or sum <= nums[i]) {
                cout << -1 << " ";
                continue;
            }

            int prev_eat = *(--it);
            if (nums[prev_eat] <= nums[prev_eat + 1])
                prev_eat--;
            int bwd_index = n - (i + 1);
            int j = upper_bound(bwd_pfx.begin(), bwd_pfx.end(), bwd_pfx[bwd_index + 1] + nums[i]) - bwd_pfx.begin() - 1;
            cout << max(i - prev_eat, j - bwd_index) << " ";
        }
        else {
            int ans1, ans2;

            {
                auto it = upper_bound(eats.begin(), eats.end(), i);
                int sum = fwd_pfx[n] - fwd_pfx[i + 1];
                if (it == eats.end() or sum <= nums[i])
                    ans1 = LONG_LONG_MAX;
                else {
                    int next_eat = *it;
                    if (nums[next_eat] <= nums[next_eat - 1])
                        next_eat++;
                    int j = upper_bound(fwd_pfx.begin(), fwd_pfx.end(), fwd_pfx[i + 1] + nums[i]) - fwd_pfx.begin() - 1;
                    ans1 = max(next_eat - i, j - i);
                }
            }

            {
                auto it = lower_bound(eats.begin(), eats.end(), i);
                int sum = fwd_pfx[i];
                if (it == eats.begin() or sum <= nums[i])
                    ans2 = LONG_LONG_MAX;
                else {
                    int prev_eat = *(--it);
                    if (nums[prev_eat] <= nums[prev_eat + 1])
                        prev_eat--;
                    int bwd_index = n - (i + 1);
                    int j = upper_bound(bwd_pfx.begin(), bwd_pfx.end(), bwd_pfx[bwd_index + 1] + nums[i]) - bwd_pfx.begin() - 1;
                    ans2 = max(i - prev_eat, j - bwd_index);
                }
            }

            int ans = min(ans1, ans2);
            cout << (ans == LONG_LONG_MAX ? -1 : ans) << " ";
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