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
    int n, m; cin >> n >> m;
    
    vi nums(n);
    for (int i = 0; i < m; i++) {
        int a; cin >> a;
        nums[a - 1]++;
    }

    int lo = 0, hi = 1e9, ans;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        int sum = 0;
        for (int i = 0; i < n; i++) {
            int a = min(mid, nums[i]);
            sum += a + (mid - a) / 2;
        }
        
        if (sum >= m)
            hi = mid - 1, ans = mid;
        else
            lo = mid + 1;
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