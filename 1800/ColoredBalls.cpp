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

const int mod = 998244353;

void add(int& a, int b) {
    a = (a + b) % mod;
}

void solve() {
    int n; cin >> n;

    v<int> nums(n);
    for (int& a : nums) cin >> a;
    sort(all(nums));

    int ans = 0;
    vector<int> cnt(5001), next(5001);
    for (int i = 0; i < n; i++) {
        add(next[nums[i]], 1);
        add(ans, nums[i]);
        for (int sum = 0; sum < 5001; sum++) {
            int amount = cnt[sum];
            if (amount == 0) continue;
            add(next[nums[i] + sum], amount);
            if (sum < nums[i])
                add(ans, nums[i] * amount % mod);
            else
                add(ans, (sum + nums[i] + 1) / 2 * amount % mod);
        }
        for (int j = 0; j < 5001; j++)
            cnt[j] = next[j];
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