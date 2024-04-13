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
    int n, m; cin >> n >> m;
    m--;

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    int ans = 0;
    if (nums[m] > 0 and m != 0) {
        nums[m] *= -1;
        ans++;
    }

    int curr = 0, min_sum = INT_MAX, min_i = -1;
    for (int i = 0; i <= m; i++) {
        curr += nums[i];
        if (curr <= min_sum) {
            min_sum = curr;
            min_i = i;
        }
    }

    priority_queue<int> max_pq;
    if (curr > min_sum) {
        int x = 0;
        for (int i = m; i > min_i; i--) {
            if (nums[i] <= 0) {
                x += nums[i];
                continue;
            }
            max_pq.push(nums[i]);
            x += nums[i];
            if (x > 0) {
                ans++;
                x -= 2 * max_pq.top();
                max_pq.pop();
            }
        }
    }

    int x = 0;
    priority_queue<int, v<int>, greater<int>> min_pq;
    for (int i = m + 1; i < n; i++) {
        x += nums[i];
        min_pq.push(nums[i]);
        while (x < 0) {
            x -= 2 * min_pq.top();
            min_pq.pop();
            ans++;
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