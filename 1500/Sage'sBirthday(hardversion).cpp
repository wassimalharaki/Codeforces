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
    sort(all(nums));

    v<int> ans;
    ans.push_back(nums[n >> 1]);
    int l = 0, r = n / 2 + 1;

    while (r < n) {
        ans.push_back(nums[l++]);
        ans.push_back(nums[r++]);
    }
    if (!(n & 1))
        ans.push_back(nums[n / 2 - 1]);
    
    int x = 0;
    for (int i = 1; i < n - 1; i++)
        if (ans[i] < ans[i - 1] and ans[i] < ans[i + 1])
            x++;

    cout << x << nl;
    for (int& a : ans)
        cout << a << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}