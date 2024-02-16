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

    int lo = 1, hi = n, ans = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        vvi piles(mid);
        int cnt = 0;
        int p = 0;
        for (int i = 0; i < n; i++)
            for (int k = 0; k < mid; k++) {
                bool can = 1;
                int sz = piles[p].size();
                for (int j = 0; j < sz; j++)
                    if (piles[p][j] < sz - j)
                        can = 0;
                if (can) {
                    piles[p].pb(nums[i]);
                    cnt++;
                    p = (++p % mid);
                    break;
                }
                p = (++p) % mid;
            }

        if (cnt == n)
            hi = mid - 1, ans = mid;
        else
            lo = mid + 1;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}