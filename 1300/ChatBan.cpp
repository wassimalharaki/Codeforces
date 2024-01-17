#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl << '\n'
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
    int k, x; cin >> k >> x;

    int lo = 1, hi = 2 * k - 1, ans = 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2, val = 0;
        
        if (mid <= k)
            val = (1 + mid) * mid / 2;
        else
            val = (1 + k) * k / 2 + (3 * k - (mid + 1)) * (mid - k) / 2;
        
        if (val <= x)
            lo = mid + 1, ans = mid + (val < x);
        else
            hi = mid - 1;
    }
    cout << min(ans, 2 * k - 1) nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}