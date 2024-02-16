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

    int curr = 1, pos = 0, neg = 0;
    vi ans(2);
    for (int i = 0; i < n; i++) {
        if (nums[i] < 0) curr *= -1;
        curr > 0 ? ans[1]++ : ans[0]++;
        ans[0] += (curr > 0 ? neg : pos);
        ans[1] += (curr > 0 ? pos : neg);
        curr > 0 ? pos++ : neg++;
    }
    cout << ans[0] << " " << ans[1];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}