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
    int n, k; cin >> n >> k;

    vi nums(n);
    for (int& a : nums) cin >> a;

    int ans = 0, curr = 1;
    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1] / 2) {
            curr++;
            continue;
        }
        ans += max(0ll, curr - k);
        curr = 1;
    }
    ans += max(0ll, curr - k);
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