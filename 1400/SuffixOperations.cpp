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

    int a = abs(nums[0] - nums[1]);
    int b = abs(nums[n - 1] - nums[n - 2]);
    int c = -INF;
    for (int i = 1; i < n - 1; i++)
        if (nums[i] > nums[i - 1] and nums[i] > nums[i + 1]
                or nums[i] < nums[i - 1] and nums[i] < nums[i + 1]) {
            int op1 = abs(nums[i] - nums[i + 1]);
            int op2 = abs(nums[i] - nums[i - 1]);
            int res = abs(nums[i - 1] - nums[i + 1]);
            c = max(c, op1 + op2 - res);
        }
    
    int ans = 0;
    for (int i = n - 1; i > 0; i--)
        ans += abs(nums[i] - nums[i - 1]);
    cout << ans - max({a, b, c}) << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}