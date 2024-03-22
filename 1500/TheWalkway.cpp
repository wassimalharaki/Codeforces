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

/*
eat at first pos
always eat if at cookie seller
otherwise check distance in between
cookies eaten in between cookie sellers
= (seller[i + 1] - (seller[i] + 1)) / d

if i remove a seller, what amount will be affected?
the amount eaten between i - 1, i, i + 1
it will be total - [i - 1, i], [i, i + 1] + [i - 1, i + 1]
min and count
*/

void solve() {
    int n, m, d; cin >> n >> m >> d;

    v<int> nums(m);
    for (int& a : nums) cin >> a;

    bool hi = nums[0] == 1;
    if (nums[0] != 1) {
        v<int> fix{1};
        for (int& a : nums) fix.push_back(a);
        nums = fix;
        m++;
    }

    auto get = [&](int r, int l) {
        return (r - l - 1) / d;
    };

    int tot = 1;
    for (int i = 1; i < m; i++)
        tot += get(nums[i], nums[i - 1]) + 1;
    tot += get(n + 1, nums.back());

    int min = INT_MAX, cnt = 0;
    for (int i = 1; i < m; i++) {
        int curr;
        if (i == m - 1)
            curr = tot - 1 - get(nums[i], nums[i - 1])
                - get(n + 1, nums[i]) + get(n + 1, nums[i - 1]);
        else
            curr = tot - 1 - get(nums[i], nums[i - 1])
                - get(nums[i + 1], nums[i]) + get(nums[i + 1], nums[i - 1]);
        if (curr < min) {
            min = curr;
            cnt = 1;
        }
        else if (curr == min)
            cnt++;
    }
    cout << min << " " << cnt + (tot == min and hi) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}