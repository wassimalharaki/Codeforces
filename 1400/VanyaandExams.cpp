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
    int n, full, avg;
    cin >> n >> full >> avg;

    vpii nums(n);
    int sum = 0;
    for (pii& p : nums) cin >> p.S >> p.F, sum += p.S;
    sort(all(nums));
    
    int ans = 0;
    for (int i = 0; i < n and sum < avg * n; i++) {
        int a = min(n * avg - sum, full - nums[i].S);
        ans += a * nums[i].F;
        sum += a;
    }
    cout << ans << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}