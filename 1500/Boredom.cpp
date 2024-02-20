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
    int n; cin >> n;

    map<int, int> map;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        map[a]++;
    }

    vpii nums;
    for (auto& p : map) 
        nums.pb(mp(p.F, p.F * p.S));
    n = nums.size();

    vi dp(n);
    dp[0] = nums[0].S;
    for (int i = 1; i < n; i++) {
        dp[i] = nums[i].S;
        if (nums[i].F == nums[i - 1].F + 1) {
            if (i - 2 >= 0)
                dp[i] += dp[i - 2];
        }
        else
            dp[i] += dp[i - 1];
        dp[i] = max(dp[i], dp[i - 1]);
    }
    cout << dp[n - 1] << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}