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
    
    int last = nums[n - 1], ans = 0;
    for (int i = n - 2; i >= 0; i--)
        if (nums[i] <= last)
            last = nums[i];
        else {
            int x = (nums[i] + last - 1) / last;
            ans += x - 1;
            last = nums[i] / x;
        }
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