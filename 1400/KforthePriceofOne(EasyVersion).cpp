#include <bits/stdc++.h>

using namespace std;

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

#define int long long
#define INF LONG_LONG_MAX
#define nl '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define F first
#define S second

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

int bruteforce(vi& nums, int k, int p) {
    int n = nums.size(), ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        vi buy;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                buy.pb(nums[i]);
        int cost = 0;
        reverse(all(buy));
        for (int i = 0; i < buy.size(); i++) {
            cost += buy[i];
            if (i + k - 1 < buy.size())
                i += k - 1;
        }
        if (cost <= p)
            ans = max(ans, (int) buy.size());
    }
    return ans;
}

void solve() {
    int n, p, k; cin >> n >> p >> k;

    vi nums(n);
    for (int& a : nums) cin >> a;
    sort(all(nums));

    vi dp(n + 1);
    for (int i = 0; i < k - 1; i++)
        dp[i + 1] = dp[i] + nums[i];
    for (int i = k; i <= n; i++)
        dp[i] = nums[i - 1] + dp[i - k];
        
    int ans = 0;
    for (int i = 0; i <= n; i++)
        if (dp[i] <= p) ans = i;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}