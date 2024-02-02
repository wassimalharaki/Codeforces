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

void solve() {
    //if n & 1
    //lo hi lo hi lo
    //else
    //lo hi lo hi lo lo
    //lo lo hi lo hi lo
    //lo hi lo lo hi lo

    //if n & 1 count = n / 2
    //else (n - 1) / 2

    //for n & 1 only 1 option
    //else many options (probably dp)
    int n; cin >> n;

    vi nums(n);
    for (int& a : nums) cin >> a;

    if (n & 1) {
        int ans = 0;
        for (int i = 1; i < n; i += 2) {
            int l = nums[i - 1] - nums[i] + 1;
            int r = nums[i + 1] - nums[i] + 1;
            ans += max({l, r, 0ll});
        }
        cout << ans << nl;
    }
    else {
        vi dp(n);
        for (int i = 1; i < n - 1; i++) {
            int l = nums[i - 1] - nums[i] + 1;
            int r = nums[i + 1] - nums[i] + 1;
            if (i == 1 or i == 2)
                dp[i] = max({l, r, 0ll});
            else {
                if (i & 1)
                    dp[i] = dp[i - 2] + max({l, r, 0ll});
                else
                    dp[i] = min(dp[i - 2], dp[i - 3]) + max({l, r, 0ll});
            }
        }
        cout << min(dp[n - 2], dp[n - 3]) << nl;
        dbg(dp);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}