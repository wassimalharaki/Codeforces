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

    int l = 0, r = 1e9;
    for (int i = 0; i < n - 1; i++)
        if (nums[i] < nums[i + 1])
            r = min(r, (nums[i] + nums[i + 1]) / 2);
        else if (nums[i] > nums[i + 1])
            l = max(l, (nums[i] + nums[i + 1] + 1) / 2);
    cout << (l > r ? -1 : r) << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}