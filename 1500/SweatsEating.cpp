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

    v<int> nums(n);
    for (int& a : nums) cin >> a;
    sort(all(nums));

    v<int> sum(m);
    for (int i = 0; i < n; i++)
        sum[i % m] += nums[i];

    v<int> ans(n);
    int curr = 0, cnt = 0, x = 1;
    for (int i = n - 1; i >= 0; i--) {
        curr += nums[i];
        if (++cnt % m == 0) {
            ans[n - 1] += curr * x++;
            cnt = curr = 0;
        }
    }
    ans[n - 1] += curr * x;

    for (int i = n - 2; i >= 0; i--) {
        ans[i] = ans[i + 1] - sum[(i + 1) % m];
        sum[(i + 1) % m] -= nums[i + 1];
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}