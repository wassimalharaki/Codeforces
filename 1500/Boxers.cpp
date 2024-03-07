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

    set<int> have;
    for (int i = 0; i < n; i++)
        if (nums[i] - 1 >= 1 and not have.count(nums[i] - 1))
            have.insert(nums[i] - 1);
        else if (not have.count(nums[i]))
            have.insert(nums[i]);
        else if (not have.count(nums[i] + 1))
            have.insert(nums[i] + 1);
    cout << have.size() << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;    
    while (T--) solve();
}