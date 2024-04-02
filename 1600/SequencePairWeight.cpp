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

    v<int> dp(n);
    map<int, pair<int, int>> cnt;
    cnt[nums[0]] = {1, 0};
    int sum = 0;
    for (int i = 1; i < n; i++) {
        auto& p = cnt[nums[i]];
        p.second += p.first;
        p.first = i + 1;
        sum += p.second;
        dp[i] = dp[i - 1] + sum;
    }
    cout << dp[n - 1] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}