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

    vi nums(n);
    for (int& a : nums) cin >> a;
    sort(rall(nums));
    int sum = accumulate(all(nums), 0ll);

    int ans = 0;
    for (int i = 1; i < n; i++) {
        int x = n - 1, y = (i ? nums[0] : nums[1]);

        int a = sum - nums[i];
        int b = x * y;
        int c = b - a;
        int d = (nums[i] > c ? (x - (nums[i] - c) % x) % x : c - nums[i]);
        ans = max(ans, d);
    }
    cout << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}