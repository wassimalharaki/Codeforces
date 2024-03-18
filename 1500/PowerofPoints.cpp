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

    v<array<int, 2>> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i][0];
        nums[i][1] = i;
    }
    sort(all(nums));

    v<int> ans(n);
    int x = 0, y = nums[0][0];
    for (auto& p : nums)
        x += p[0] - y + 1;
    ans[nums[0][1]] = x;
    for (int i = 1; i < n; i++) {
        x += (nums[i][0] - y) * (2 * i - n);
        ans[nums[i][1]] = x;
        y = nums[i][0];
    }

    for (int& a : ans) cout << a << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}