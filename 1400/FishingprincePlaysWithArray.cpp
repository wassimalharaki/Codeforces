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
    vi a(n);
    for (int& x : a) cin >> x;

    int k; cin >> k;
    vi b(k);
    for (int& x : b) cin >> x;

    vpii block_a, block_b;
    for (int i = 0; i < n; i++) {
        pii p = mp(a[i], 1);
        while (p.F % m == 0) {
            p.F /= m;
            p.S *= m;
        }
        if (block_a.empty() or block_a.back().F != p.F)
            block_a.pb(p);
        else
            block_a.back().S += p.S;
    }
    
    for (int i = 0; i < k; i++) {
        pii p = mp(b[i], 1);
        while (p.F % m == 0) {
            p.F /= m;
            p.S *= m;
        }
        if (block_b.empty() or block_b.back().F != p.F)
            block_b.pb(p);
        else
            block_b.back().S += p.S;
    }

    cout << (block_a == block_b ? "YES" : "NO") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}