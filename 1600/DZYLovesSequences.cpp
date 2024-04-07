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

int get_ans(v<int>& nums) {
    int ans = 1, curr = 1, n = nums.size();
    for (int i = 1; i < n; i++)
        if (nums[i] > nums[i - 1])
            ans = max(ans, ++curr);
        else
            curr = 1;
    return ans;
}

void solve() {
    int n; cin >> n;

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    v<bool> bad(n), fix(n);
    bad[n - 1] = 1;
    for (int i = 1; i < n; i++)
        if (nums[i] <= nums[i - 1]) {
            bad[i] = 1;
            if (i - 2 < 0 or nums[i - 2] < nums[i] - 1)
                fix[i] = 1;
        }
    
    if (n == 1) {
        cout << 1 << nl;
        return;
    }

    int ans = min(get_ans(nums) + 1, n);
    for (int i = 0; i < n; i++) {
        if (not bad[i]) continue;
        int me = nums[i - 1] + 1, prev = nums[i - 1];
        if (fix[i])
            me = nums[i], prev = nums[i] - 1;

        int l = i - 2;
        for (; l >= 0; l--)
            if (nums[l] < prev)
                prev = nums[l];
            else break;

        int r = i + 1;
        for (; r < n; r++)
            if (nums[r] > me)
                me = nums[r];
            else break;

        ans = max(ans, r - l - 1);
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