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
    int n, m, d; cin >> n >> m >> d;

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    int curr = 0, ans = 0;
    priority_queue<int, v<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        ans = max(ans, curr + nums[i] - (i + 1) * d);
        if (nums[i] <= 0)
            continue;
        else if (pq.size() != m - 1) {
            curr += nums[i];
            pq.push(nums[i]);
        }
        else if (pq.size() and pq.top() < nums[i]) {
            curr -= pq.top();
            curr += nums[i];
            pq.pop();
            pq.push(nums[i]);
        }
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