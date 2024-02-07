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
    int n, u, r, d, l;
    cin >> n >> u >> r >> d >> l;
    if (d > u) swap(u, d);
    if (l > r) swap(r, l);

    if (u) {
        if (r)
            r--, u--;

        if (d > u) {
            if (l > 1 and u)
                l--, u--;
        }
        else {
            if (l and u)
                l--, u--;
        }
        
        if (u > n - 2) {
            cout << "NO" << nl;
            return;
        }
    }
    
    if (l > r) swap(r, l);
    if (d) {
        if (r)
            r--, d--;
        if (l and d)
            l--, d--;
 
        if (d > n - 2) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << (r > n - 2 or l > n - 2 ? "NO" : "YES") << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}