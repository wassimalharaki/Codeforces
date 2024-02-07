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
    
    vi a(n), b(n), c(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    for (int i = 0; i < n; i++)
        c[a[i] / 2] = i;
    
    vi pref(n);
    pref[0] = c[0];
    for (int i = 1; i < n; i++)
        pref[i] = min(c[i], pref[i - 1]);
    
    int ans = INF;
    for (int i = 0; i < n; i++)
        ans = min(ans, i + pref[(b[i] - 1) / 2]);
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