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
    int n, m; cin >> n >> m;
    
    v<int> nums(n);
    for (int& a : nums) cin >> a;
    sort(nums.rbegin(), nums.rend());
 
    int lo = 1, hi = n, ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
 
        v<pair<int, int>> splits(mid);
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < splits[j].second) break;
            splits[j].first += nums[i];
            splits[j].second++;
            j++; j %= mid;
        }
 
        int sum = 0;
        for (int i = 0; i < mid; i++)
            sum += splits[i].first - (splits[i].second) * (splits[i].second - 1) / 2;
            
        if (sum >= m)
            ans = mid, hi = mid - 1;
        else
            lo = mid + 1;
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}