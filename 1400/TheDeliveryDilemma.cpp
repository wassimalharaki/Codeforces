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

    vpii nums(n);
    for (pii& a : nums) cin >> a.F;
    for (pii& a : nums) cin >> a.S;
    sort(rall(nums));

    int ans, x = 0;
    for (int i = 0; i < n; i++) {
        ans = nums[i].F;
        if (nums[i].S > nums[i].F)
            break;
        if (x + nums[i].S < ans)
            x += nums[i].S, ans = 0;
        else
            break;
    }
    cout << max(ans, x) << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}