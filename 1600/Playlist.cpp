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
    for (auto& a : nums)
        cin >> a[1] >> a[0];
    sort(nums.begin(), nums.end());
    
    priority_queue<int, v<int>, greater<int>> pq;
    int sum = 0, ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (pq.size() < k)
            ans = max(ans, (sum + nums[i][1]) * nums[i][0]);
        else
            ans = max(ans, (sum - pq.top() + nums[i][1]) * nums[i][0]);

        sum += nums[i][1];
        pq.push(nums[i][1]);
        if (pq.size() > k) {
            sum -= pq.top();
            pq.pop();
        }
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