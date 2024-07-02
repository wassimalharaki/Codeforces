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
    int n, k; cin >> n >> k;

    v<array<int, 2>> nums(n);
    for (auto& a : nums) cin >> a[0];
    for (auto& a : nums) cin >> a[1];
    sort(nums.begin(), nums.end(), [](auto& l, auto& r) {
        if (l[1] == r[1])
            return l[0] < r[0];
        return l[1] < r[1];
    });

    auto alice = nums;
    for (int i = 0; i < n; i++)
        alice[i][1] = i;
    sort(alice.begin(), alice.end());

    int x = 0, y = 0, ans = 0;
    set<int> bad, use;
    for (int i = 0; i < k; i++) {
        use.insert(alice[i][1]);
        x += alice[i][0];
    }
    int j = k;

    for (int i = 0; i < n - k; i++) {
        bad.insert(i);
        if (use.count(i)) {
            x -= nums[i][0];
            use.erase(i);
            while (bad.count(alice[j][1])) j++;

            x += alice[j][0];
            use.insert(alice[j][1]);
            j++;
        }
        y += max(nums[i][1] - nums[i][0], 0ll);
        ans = max(ans, y - x);
    }
    cout << ans << nl; 
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}