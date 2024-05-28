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
    int n, l; cin >> n >> l;

    v<array<int, 2>> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i][0] >> nums[i][1];
    sort(nums.begin(), nums.end(), [](auto& l, auto& r) {
        if (l[1] == r[1])
            return l[0] < r[0];
        return l[1] < r[1];
    });

    auto check = [&](int k) -> bool {
        for (int i = 0; i <= n - k; i++) {
            priority_queue<int> pq;
            int sum = 0;
            for (int j = i; j < i + k; j++)
                pq.push(nums[j][0]), sum += nums[j][0];
            if (sum + nums[i + k - 1][1] - nums[i][1] <= l)
                return 1;
            for (int j = i + k; j < n; j++) {
                if (not pq.empty() and pq.top() > nums[j][0]) {
                    sum -= pq.top();
                    pq.pop();
                    pq.push(nums[j][0]);
                    sum += nums[j][0];
                }
                if (sum + nums[j][1] - nums[i][1] <= l)
                    return 1;
            }
        }
        return 0;
    };

    int lo = 1, hi = n, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (check(mid))
            lo = mid + 1, ans = mid;
        else
            hi = mid - 1;
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