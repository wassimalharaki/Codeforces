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

v<int> with(10), without(10);

int getw(int x) {
    return x < 0 ? without[9] : with[x];
}

int getwout(int x) {
    return x < 0 ? 0 : without[x];
}

void solve() {
    int n; cin >> n;
    string s = to_string(n);
    reverse(all(s));
    v<int> nums(s.size());
    for (int i = 0; i < s.size(); i++)
        nums[i] = s[i] - '0';
    
    v<array<int, 4>> dp(s.size(), {0, 0, 0, 0});
    dp[0] = {getwout(nums[0]), 0, getw(nums[0]), 0};
    for (int i = 1; i < s.size(); i++) {
        dp[i][0] = dp[i - 1][0] * getwout(nums[i]) + dp[i - 1][1] * getwout(nums[i] - 1);
        dp[i][1] = dp[i - 1][2] * getwout(nums[i]) + dp[i - 1][3] * getwout(nums[i] - 1);
        dp[i][2] = dp[i - 1][0] * getw(nums[i])    + dp[i - 1][1] * getw(nums[i] - 1);
        dp[i][3] = dp[i - 1][2] * getw(nums[i])    + dp[i - 1][3] * getw(nums[i] - 1);
    }
    cout << dp.back()[0] - 2 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    with[0] = 9;
    for (int i = 1; i < 10; i++)
        with[i] = with[i - 1] - 1;
    without[0] = 1;
    for (int i = 1; i < 10; i++)
        without[i] = without[i - 1] + 1;

    int T = 1;
    cin >> T;
    while (T--) solve();
}