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
 
    vi a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
 
    int lo = 0, hi = 2e9, ans;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int x = 0;
        for (int i = 0; i < n; i++) {
            x += a[i] * mid - min(a[i] * mid, b[i]);
            if (x > k) break;
        }
        
        if (x - k <= 0)
            ans = mid, lo = mid + 1;
        else
            hi = mid - 1;
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